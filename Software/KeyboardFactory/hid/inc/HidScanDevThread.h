#pragma once

#include <QThread>

#include "HIDUtil.h"

class HidScanDevThread : public QThread {

    Q_OBJECT

private:
    HIDUtil* hidUtil = nullptr;
    DEV_LIST_T oldDevList;

public:
    [[nodiscard]] HIDUtil *getHidUtil() const;
    void setHidUtil(HIDUtil *hidUtil);

protected:
    [[noreturn]] void run() override;

private:
    void scanDevices();
    bool isDevListChanged(DEV_LIST_T* devList);

signals:
    void devListChanged(DEV_LIST_T* newList);

};