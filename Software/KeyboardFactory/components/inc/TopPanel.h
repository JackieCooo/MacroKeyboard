#pragma once

#include <QWidget>
#include <QLabel>
#include <QComboBox>
#include <QHBoxLayout>
#include <QSizePolicy>

#include "HIDService.h"
#include "HIDUtil.h"

class TopPanel : public QWidget {

private:
    QHBoxLayout* hLayout = nullptr;
    QLabel* label = nullptr;
    QComboBox* deviceList = nullptr;

    HIDService* hidService = nullptr;

public:
    TopPanel();
    explicit TopPanel(QWidget* parent);
    void setHIDService(HIDService* service);

private:
    void setupUI();

private slots:
    void updateDeviceList(DEV_LIST_T* newList);

};