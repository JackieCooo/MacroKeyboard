#include "HidReceiveThread.h"

/**
  * @brief HID设备接收监听线程
  * @param 无
  * @retval 无
  */
[[noreturn]] void HidReceiveThread::run() {
    uint8_t buf[MAX_RX_BUF_LEN];
    memset(buf, 0x00, MAX_RX_BUF_LEN);
    while(true) {
        hidUtil->GetDataFormHidDevice(buf, MAX_RX_BUF_LEN, READ_INTERRUPT, MODE_SYNC);
        emit hidDataReceived(buf);  // 发送数据接收成功信号
        qDebug("received data");
    }
}

/**
  * @brief 获取HID工具类
  * @param 无
  * @retval 返回指向HID工具类的指针
  */
HIDUtil *HidReceiveThread::getHidUtil() const {
    return hidUtil;
}

/**
  * @brief 设置HID工具类
  * @param hidUtil HID工具类对象
  * @retval 无
  */
void HidReceiveThread::setHidUtil(HIDUtil *hidUtil) {
    this->hidUtil = hidUtil;
}
