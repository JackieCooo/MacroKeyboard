#include "HidService.h"

/**
  * @brief HID服务类构造函数
  * @param 无
  * @retval 无
  */
HidService::HidService() {
    // 绑定当前设备改变信号到全局
    connect(this, SIGNAL(curDevChanged(HIDDevInterface*)), GlobalEvent::getInstance(), SIGNAL(bridgeCurDevChanged(HIDDevInterface*)));
}

/**
  * @brief 启动HID设备扫描线程
  * @param 无
  * @retval 无
  */
void HidService::startScanService() {
    if (scanThread == nullptr) {
        scanThread = new HidScanDevThread();
    }
    scanThread->setHidUtil(&hidUtil);
    // 绑定设备列表改变信号到全局
    connect(scanThread, SIGNAL(devListChanged(DEV_LIST_T*)), GlobalEvent::getInstance(), SIGNAL(bridgeDevListChanged(DEV_LIST_T*)));
    scanThread->start();
}

/**
  * @brief 启动HID设备接收监听线程
  * @param 无
  * @retval 无
  */
void HidService::startListenService() {
    if (curDev == nullptr) return;

    if (receiveThread == nullptr) {
        receiveThread = new HidReceiveThread();
    }
    receiveThread->setHidUtil(&hidUtil);
    // 绑定数据接收成功信号到全局
    connect(receiveThread, SIGNAL(hidDataReceived(uint8_t*)), GlobalEvent::getInstance(), SIGNAL(bridgeHidDataReceived(uint8_t*)));
    receiveThread->start();
}

/**
  * @brief 获取当前的HID设备
  * @param 无
  * @retval 返回指向当前HID设备的指针
  */
HIDDevInterface *HidService::getCurDev() const {
    return curDev;
}

/**
  * @brief 设置当前HID设备
  * @param dev HID设备
  * @retval 无
  */
void HidService::setCurDev(HIDDevInterface *dev) {
    if (curDev == dev) return;
    this->curDev = dev;
    emit curDevChanged(curDev);  // 发送当前设备改变信号
    bool Result;
    Result = hidUtil.OpenHidDevice(curDev->getVendorId(), curDev->getProductId(), MODE_SYNC);
    if (Result == false) {
        qDebug("device open failed");
        return;
    }
    startListenService();  // 开启设备监听线程
}
