#include "HidReceiveThread.h"

[[noreturn]] void HidReceiveThread::run() {
    uint8_t buf[MAX_RX_BUF_LEN];
    memset(buf, 0x00, MAX_RX_BUF_LEN);
    while(true) {
        hidUtil->GetDataFormHidDevice(buf, MAX_RX_BUF_LEN, READ_INTERRUPT, MODE_SYNC);
        emit hidDataReceived(buf);  // 发送数据接收成功信号
        qDebug("received data");
    }
}

HIDUtil *HidReceiveThread::getHidUtil() const {
    return hidUtil;
}

void HidReceiveThread::setHidUtil(HIDUtil *hidUtil) {
    this->hidUtil = hidUtil;
}
