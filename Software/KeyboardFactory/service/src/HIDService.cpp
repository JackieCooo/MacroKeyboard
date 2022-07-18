#include "HIDService.h"

HIDService::HIDService() {

}

[[noreturn]] void HIDService::run() {
    while (true) {
        scanDevices();
        QThread::msleep(100);
    }
}

void HIDService::scanDevices() {
    auto result = hidUtil.FindHidDevice(1155, ANY_PID);
    if (isDevListChanged(result)) {
        deviceList = *result;
        emit devListChanged(&deviceList);  // 发送设备列表更新信号
        cout << "DevList update" << endl;
    }
}

bool HIDService::isDevListChanged(DEV_LIST_T *devList) {
    auto i = deviceList.begin();
    auto j = devList->begin();
    for(; ; ++i, ++j) {
        if (i == deviceList.end() && j == devList->end()) break;
        if (i == deviceList.end() || j == devList->end() || (*i)->getProductId() != (*j)->getProductId()) return true;
    }
    return false;
}

DEV_LIST_T HIDService::getDeviceList() const {
    return deviceList;
}

void HIDService::setDeviceList(DEV_LIST_T deviceList) {
    this->deviceList = deviceList;
}

