#include "QtWidgetsApplication1.h"
#include "backend.h"
#include "stabilizer.h"
#include <QLocale>
#include <QTranslator>
#include <Windows.h>
#include <initguid.h>
#include <mmdeviceapi.h>
#include <endpointvolume.h>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QSettings>
#include <QIcon>
#include <QQmlContext>
#include <QApplication>
#include <QMessageBox>
wchar_t* GetWC(const char* c)
{
    const size_t cSize = strlen(c) + 1;
    wchar_t* wc = new wchar_t[cSize];
    mbstowcs(wc, c, cSize);

    return wc;
}
bool initialize_app(IMMDeviceEnumerator*& pEnumerator, IAudioEndpointVolume*& endpointVolume,
    IAudioMeterInformation*& pMeterInfo, IMMDevice*& pDevice) {
    HRESULT hr = CoInitialize(NULL);
    if (FAILED(hr)) {
        return false;
    }
    hr = CoCreateInstance(__uuidof(MMDeviceEnumerator), NULL, CLSCTX_INPROC_SERVER, __uuidof(IMMDeviceEnumerator), (void**)&pEnumerator);
    if (FAILED(hr)) {
        return false;
    }
    hr = pEnumerator->GetDefaultAudioEndpoint(eRender, eConsole, &pDevice);
    if (FAILED(hr)) {
        return false;
    }
    _GUID audio_meter_id;
    std::string str = "{C02216F6-8C67-4B5B-9D00-D008E73E0064}";
    LPOLESTR lpolestr = GetWC(str.c_str());
    hr = IIDFromString(lpolestr, &audio_meter_id);
    if (FAILED(hr)) {
        delete[] lpolestr;
        return false;
    }
    hr = pDevice->Activate(audio_meter_id, CLSCTX_ALL, NULL, (void**)&pMeterInfo);
    delete[] lpolestr;
    if (FAILED(hr)) {
        return false;
    }
    _GUID audio_endpoint_volume;
    std::string enpoint_str = "{5CDF2C82-841E-4546-9722-0CF74078229A}";
    LPOLESTR enpoint_lpolestr = GetWC(str.c_str());
    hr = IIDFromString(enpoint_lpolestr, &audio_endpoint_volume);
    if (FAILED(hr)) {
        delete[] enpoint_lpolestr;
        return false;
    }
    hr = pDevice->Activate(__uuidof(IAudioEndpointVolume),
        CLSCTX_INPROC_SERVER, NULL, (LPVOID*)&endpointVolume);
    delete[] enpoint_lpolestr;
    if (FAILED(hr)) {
        return false;
    }
    float volume_level = 0;
    hr = endpointVolume->GetMasterVolumeLevelScalar(&volume_level);
    assert(!FAILED(hr));
    return true;
}


int main(int argc, char *argv[])
{
    IMMDeviceEnumerator* pEnumerator = nullptr;
    IMMDevice* pDevice = nullptr;
    IAudioEndpointVolume* endpointVolume = nullptr;
    IAudioMeterInformation* pMeterInfo = nullptr;

    QGuiApplication app_gui(argc, argv);
    bool initialization = initialize_app(pEnumerator, endpointVolume, pMeterInfo, pDevice);
    //app didn't initialize successfully
    if (!initialization) {
        QApplication app(argc, argv);
        QMessageBox msgBox;
        msgBox.setWindowTitle("Error!");
        msgBox.setText("Error during initialization");
        QPixmap pixmap(":/resources/img/error_icon.png");

        msgBox.setIconPixmap(pixmap.scaled(30, 30, Qt::KeepAspectRatio));
        msgBox.exec();
        return app.exec();
    }
    Stabilizer* stabilizer = new Stabilizer(pEnumerator, endpointVolume, pMeterInfo, pDevice);
    BackEnd backend(stabilizer);

    QGuiApplication::setApplicationName("AudioStabilizer");
    QGuiApplication::setOrganizationName("Yousef Shora");


    QIcon::setThemeName("Material Style");
    
    QQmlApplicationEngine engine;

    engine.load(QUrl("qrc:/stabilizer.qml"));

    if (engine.rootObjects().isEmpty())
        return -1;

    QQmlContext* rootContext = engine.rootContext();

    rootContext->setContextProperty("classStabilizer",&backend);
   
    app_gui.setWindowIcon(QIcon(":/resources/img/stabilizer.ico"));

    return app_gui.exec();
}
