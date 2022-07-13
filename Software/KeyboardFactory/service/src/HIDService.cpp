#include "HIDService.h"

[[noreturn]] void HIDService::run() {
    while (true) {
        scanDevices();
        QThread::msleep(10);
    }
}

void HIDService::scanDevices() {
    hid_device_info* newList = hid_enumerate(ANY_VID, ANY_PID);  // 枚举所有VID和PID设备
    if (!isDeviceListEqual(deviceList, newList)) {
        deviceList = newList;
        emit enumListChanged(deviceList);  // 发送信号
    }
}

bool HIDService::isDeviceListEqual(hid_device_info *a, hid_device_info *b) {
    hid_device_info* i = a;
    hid_device_info* j = b;
    for (; ; i = i->next, j = j->next) {
        if (i == nullptr && j == nullptr) return true;
        if (i == nullptr || j == nullptr || i->path != j->path) break;
    }

    return false;
}
