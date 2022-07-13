#include "BrightnessService.h"

BrightnessService::BrightnessService() {

    loadLibrary();  // 加载动态库

    monitor = MonitorFromWindow(nullptr, MONITOR_DEFAULTTOPRIMARY);

    isInitSuccessful = getNumsOfPhysicalMonitor(monitor, &physicalMonitorNumber);

    if (isInitSuccessful) {
        physicalMonitor = (LPPHYSICAL_MONITOR) malloc(physicalMonitorNumber * sizeof(LPPHYSICAL_MONITOR));
        if (nullptr != physicalMonitor) {
            isInitSuccessful = getPhysicalMonitors(monitor, physicalMonitorNumber, physicalMonitor);
            if (isInitSuccessful) {

                HANDLE ppp = physicalMonitor[0].hPhysicalMonitor;
                isInitSuccessful = getSysBrightness(ppp, &minVal, &curVal, &maxVal);

                curMonitorHandler = ppp;
            }
        }
    }
}

BrightnessService::~BrightnessService() {
    if (nullptr != physicalMonitor)
        destroyPhysicalMonitors(physicalMonitorNumber, physicalMonitor);

    if (nullptr != physicalMonitor)
    {
        free(physicalMonitor);
        physicalMonitor   = nullptr;
    }

    FreeLibrary(hInst);
    hInst = nullptr;
}

int BrightnessService::getBrightness() {
    if (isInitSuccessful) {
        isInitSuccessful = getSysBrightness(curMonitorHandler, &minVal, &curVal, &maxVal);
    }

    return (int)curVal;
}

void BrightnessService::setBrightness(int val) {
    if (isInitSuccessful) {
        setSysBrightness(curMonitorHandler, (DWORD)val);
    }
}

int BrightnessService::getMinVal() const {
    return (int)minVal;
}

int BrightnessService::getMaxVal() const {
    return (int)maxVal;
}

void BrightnessService::loadLibrary() {
    hInst = LoadLibrary(L"dxva2.dll");

    if (hInst == nullptr) {
        cout << "初始化失败" << endl;
        FreeLibrary(hInst);
    }

    getSysBrightness = (GetSysBrightnessFunc)GetProcAddress(hInst, "GetMonitorBrightness");
    setSysBrightness = (SetSysBrightnessFunc)GetProcAddress(hInst, "SetMonitorBrightness");
    getNumsOfPhysicalMonitor = (GetNumsOfPhysicalMonitorFunc)GetProcAddress(hInst, "GetNumberOfPhysicalMonitorsFromHMONITOR");
    getPhysicalMonitors = (GetPhysicalMonitorsFunc) GetProcAddress(hInst, "GetPhysicalMonitorsFromHMONITOR");
    destroyPhysicalMonitors = (DestroyPhysicalMonitorsFunc) GetProcAddress(hInst, "DestroyPhysicalMonitors");

    cout << &getSysBrightness << endl;
    cout << &setSysBrightness << endl;
    cout << &getNumsOfPhysicalMonitor << endl;
    cout << &getPhysicalMonitors << endl;
    cout << &destroyPhysicalMonitors << endl;
}
