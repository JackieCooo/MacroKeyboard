#pragma once

#include "HIDUtil.h"
#include "HidScanDevThread.h"
#include "HidReceiveThread.h"
#include "HIDDevInterface.h"
#include "GlobalEvent.h"

#include <QObject>
#include <QDebug>

#define MAX_RX_BUF_LEN 2  // 最大接收数据大小

class HidService;

extern HidService* hidService;

class HidService : public QObject{

    Q_OBJECT

private:
    DEV_LIST_T* deviceList = nullptr;
    HIDUtil hidUtil;
    HidScanDevThread* scanThread = nullptr;
    HidReceiveThread* receiveThread = nullptr;
    HIDDevInterface* curDev = nullptr;

public:
    HidService();
    void startScanService();
    [[nodiscard]] HIDDevInterface *getCurDev() const;
    void setCurDev(HIDDevInterface *dev);
    void startListenService();

signals:
    void curDevChanged(HIDDevInterface* newDev);

};
