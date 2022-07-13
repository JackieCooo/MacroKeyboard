#pragma once

#include <physicalmonitorenumerationapi.h>
#include <highlevelmonitorconfigurationapi.h>
#include <windows.h>
#include <iostream>

using namespace std;

class BrightnessService {

typedef bool (*GetSysBrightnessFunc)(HANDLE, LPDWORD, LPDWORD, LPDWORD);
typedef bool (*SetSysBrightnessFunc)(HANDLE, DWORD);
typedef bool (*GetNumsOfPhysicalMonitorFunc)(HMONITOR, LPDWORD);
typedef bool (*GetPhysicalMonitorsFunc)(HMONITOR, DWORD, LPPHYSICAL_MONITOR);
typedef bool (*DestroyPhysicalMonitorsFunc)(DWORD, LPPHYSICAL_MONITOR);

private:
    DWORD minVal = 0;
    DWORD maxVal = 0;
    DWORD curVal = 0;
    bool isInitSuccessful = false;
    HANDLE curMonitorHandler = nullptr;
    HMONITOR monitor = nullptr;
    DWORD physicalMonitorNumber = 0;
    LPPHYSICAL_MONITOR physicalMonitor = nullptr;
    HINSTANCE hInst = nullptr;

    GetSysBrightnessFunc getSysBrightness = nullptr;
    SetSysBrightnessFunc setSysBrightness = nullptr;
    GetNumsOfPhysicalMonitorFunc getNumsOfPhysicalMonitor = nullptr;
    GetPhysicalMonitorsFunc getPhysicalMonitors = nullptr;
    DestroyPhysicalMonitorsFunc destroyPhysicalMonitors = nullptr;

public:
    BrightnessService();
    virtual ~BrightnessService();
    void setBrightness(int val);
    int getBrightness();
    [[nodiscard]] int getMinVal() const;
    [[nodiscard]] int getMaxVal() const;

private:
    void loadLibrary();

};
