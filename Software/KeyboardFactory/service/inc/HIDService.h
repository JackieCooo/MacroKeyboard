#pragma once

#include "hidapi.h"

#include <QThread>

class HIDService : public QThread{

#define ANY_VID 0
#define ANY_PID 0

private:
    hid_device_info* deviceList = nullptr;

protected:
    [[noreturn]] void run() override;

public:
    HIDService() = default;

private:
    void scanDevices();
    static bool isDeviceListEqual(hid_device_info* a, hid_device_info* b);

signals:
    void enumListChanged(hid_device_info* enumList);

};