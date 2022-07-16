#include "HIDService.h"

[[noreturn]] void HIDService::run() {
    while (true) {
        scanDevices();
        QThread::msleep(10);
    }
}

void HIDService::scanDevices() {
    auto result = hidUtil.FindHidDevice(1155, ANY_PID);
    if (isDevListChanged(result)) {
        emit devListChanged(result);  // 发送设备列表更新信号
    }
}

bool HIDService::isDevListChanged(DEV_LIST_T *devList) {
    return this->deviceList == nullptr || this->deviceList != devList;
}

