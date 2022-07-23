#include "HidScanDevThread.h"

/**
  * @brief HID设备扫描线程
  * @param 无
  * @retval 无
  */
[[noreturn]] void HidScanDevThread::run() {
    while (true) {
        scanDevices();
        QThread::msleep(100);
    }
}

/**
  * @brief 扫描HID设备
  * @param 无
  * @retval 无
  */
void HidScanDevThread::scanDevices() {
    auto result = hidUtil->FindHidDevice(1155, ANY_PID);
    if (isDevListChanged(result)) {
        oldDevList = *result;
        emit devListChanged(result);  // 发送设备列表更新信号
        qDebug("device list update");
    }
}

/**
  * @brief 判断设备列表是否发生改变
  * @param devList 最新扫描的设备列表
  * @retval true 设备列表改变
  *         false 设备列表不变
  */
bool HidScanDevThread::isDevListChanged(DEV_LIST_T *devList) {
    auto i = oldDevList.begin();
    auto j = devList->begin();
    for(; ; ++i, ++j) {
        if (i == oldDevList.end() && j == devList->end()) break;
        if (i == oldDevList.end() || j == devList->end() || (*i)->getProductId() != (*j)->getProductId()) return true;
    }
    return false;
}

/**
  * @brief 获取HID工具类
  * @param 无
  * @retval 返回指向HID工具类的指针
  */
HIDUtil *HidScanDevThread::getHidUtil() const {
    return hidUtil;
}

/**
  * @brief 设置HID工具类
  * @param hidUtil HID工具类对象
  * @retval 无
  */
void HidScanDevThread::setHidUtil(HIDUtil *hidUtil) {
    this->hidUtil = hidUtil;
}
