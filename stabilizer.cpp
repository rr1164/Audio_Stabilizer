#include "stabilizer.h"
#include <QDebug>

Stabilizer::Stabilizer(IMMDeviceEnumerator*& penumerator, IAudioEndpointVolume*& endpointvolume,
    IAudioMeterInformation*& pmeterInfo, IMMDevice*& pdevice) {
    pEnumerator = penumerator;
    endpointVolume = endpointvolume;
    pMeterInfo = pmeterInfo;
    pDevice = pdevice;
    HRESULT hr = endpointVolume->GetMasterVolumeLevelScalar(&original_volume);
    assert(!FAILED(hr));
}
float Stabilizer::stabilize_audio(bool increase_low_audio, bool decrease_high_audio,
    float coefficient,float Original_volume) {
    if (Original_volume != -1)
        original_volume = Original_volume;
    float audiolevel = 0;
    bool restarting = false;
    pMeterInfo->GetPeakValue(&audiolevel);
    float current_volume = 0;
    HRESULT hr = endpointVolume->GetMasterVolumeLevelScalar(&current_volume);
    assert(!FAILED(hr));
    if (!audiolevel) {
        if (!restarting) {
            //first millisecond of no sound output
            endpointVolume->SetMasterVolumeLevelScalar(original_volume, nullptr);
        }
        restarting = true;
    }
    else {
        //check if the current volume is larger than the average of decibels across the media session
        if (audiolevel > original_volume) {
            if (decrease_high_audio)
                endpointVolume->SetMasterVolumeLevelScalar(
                    (audiolevel + original_volume) / coefficient, nullptr);
            else
                endpointVolume->SetMasterVolumeLevelScalar(original_volume, nullptr);
        }
        else {
            if (increase_low_audio)
                endpointVolume->SetMasterVolumeLevelScalar(original_volume + (original_volume - audiolevel), nullptr);

            else
                endpointVolume->SetMasterVolumeLevelScalar(original_volume, nullptr);

        }
        restarting = false;
    }
    return current_volume;
}
int Stabilizer::get_original_volume() {
    return round(original_volume*100);
}
Stabilizer::~Stabilizer() {
}
