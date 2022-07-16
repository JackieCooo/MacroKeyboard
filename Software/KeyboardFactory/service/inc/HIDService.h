#pragma once

#include "HIDUtil.h"

#include <QThread>

class HIDService : public QThread{

    Q_OBJECT

private:
    DEV_LIST_T* deviceList = nullptr;
    HIDUtil hidUtil;

protected:
    [[noreturn]] void run() override;

public:
    HIDService() = default;

private:
    void scanDevices();
    bool isDevListChanged(DEV_LIST_T* devList);

signals:
    void devListChanged(DEV_LIST_T* devList);

};