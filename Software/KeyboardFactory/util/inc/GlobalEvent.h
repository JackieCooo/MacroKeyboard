#pragma once

#include <QObject>
#include <QMutex>

#include "HIDDevInterface.h"
#include "HIDUtil.h"

class GlobalEvent : public QObject {

    Q_OBJECT

public:
    static GlobalEvent* getInstance();
    GlobalEvent& operator= (GlobalEvent&) = delete;
    GlobalEvent(GlobalEvent&) = delete;

private:
    explicit GlobalEvent(QObject* parent = nullptr);

private:
    static GlobalEvent* globalEventPtr;
    static QMutex mutex;

signals:
    void bridgeCurDevChanged(HIDDevInterface* newDev);
    void bridgeDevListChanged(DEV_LIST_T* newDevList);
    void bridgeHidDataReceived(uint8_t* rxBuf);
};
