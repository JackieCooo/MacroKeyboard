#include "HidScanDevThread.h"

[[noreturn]] void HidScanDevThread::run() {
    while (true) {
        scanDevices();
        QThread::msleep(100);
    }
}

void HidScanDevThread::scanDevices() {
    auto result = hidUtil->FindHidDevice(1155, ANY_PID);
    if (isDevListChanged(result)) {
        oldDevList = *result;
        emit devListChanged(result);  // 发送设备列表更新信号
        qDebug("device list update");
    }
}

bool HidScanDevThread::isDevListChanged(DEV_LIST_T *devList) {
    auto i = oldDevList.begin();
    auto j = devList->begin();
    for(; ; ++i, ++j) {
        if (i == oldDevList.end() && j == devList->end()) break;
        if (i == oldDevList.end() || j == devList->end() || (*i)->getProductId() != (*j)->getProductId()) return true;
    }
    return false;
}

HIDUtil *HidScanDevThread::getHidUtil() const {
    return hidUtil;
}

void HidScanDevThread::setHidUtil(HIDUtil *hidUtil) {
    this->hidUtil = hidUtil;
}
