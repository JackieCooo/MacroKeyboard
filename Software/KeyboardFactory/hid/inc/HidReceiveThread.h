#pragma once

#include <QThread>

#include "HIDUtil.h"

#define MAX_RX_BUF_LEN 2

class HidReceiveThread : public QThread {

    Q_OBJECT

private:
    HIDUtil* hidUtil = nullptr;

public:
    HidReceiveThread() = default;
    [[nodiscard]] HIDUtil *getHidUtil() const;
    void setHidUtil(HIDUtil *hidUtil);

protected:
    [[noreturn]] void run() override;

signals:
    void hidDataReceived(uint8_t* buf);

};