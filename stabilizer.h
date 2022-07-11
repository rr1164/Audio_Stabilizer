#ifndef STABILIZER_H
#define STABILIZER_H
#include <Windows.h>
#include <mmdeviceapi.h>
#include <endpointvolume.h>
class Stabilizer
{
public:
    Stabilizer(IMMDeviceEnumerator*& pEnumerator, IAudioEndpointVolume*& endpointVolume,
        IAudioMeterInformation*& pMeterInfo, IMMDevice*& pDevice);
    float stabilize_audio(bool increase_low_audio, bool decrease_high_audio,
        float coefficient, float Original_volume);
    int get_original_volume();
    ~Stabilizer();
private:
    IMMDeviceEnumerator* pEnumerator = nullptr;
    IMMDevice* pDevice = nullptr;
    IAudioEndpointVolume* endpointVolume = nullptr;
    IAudioMeterInformation* pMeterInfo = nullptr;
    float original_volume = 0;

};

#endif // STABILIZER_H
