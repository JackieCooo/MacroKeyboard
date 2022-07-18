#pragma once

#include "HIDUtil.h"

#include <QThread>

class HIDService : public QThread{

    Q_OBJECT

private:
    DEV_LIST_T deviceList;
    HIDUtil hidUtil;

protected:
    [[noreturn]] void run() override;

public:
    HIDService();
    DEV_LIST_T getDeviceList() const;
    void setDeviceList(DEV_LIST_T deviceList);

private:
    void scanDevices();
    bool isDevListChanged(DEV_LIST_T* devList);

signals:
    void devListChanged(DEV_LIST_T* service);

};