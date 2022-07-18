#pragma once

#include <QWidget>
#include <QLabel>
#include <QComboBox>
#include <QHBoxLayout>
#include <QSizePolicy>

#include "HIDService.h"
#include "HIDUtil.h"
#include "GlobalData.h"

class TopPanel : public QWidget {

    Q_OBJECT

private:
    QHBoxLayout* hLayout = nullptr;
    QLabel* label = nullptr;
    QComboBox* comboBox = nullptr;

    HIDService* hidService = nullptr;

public:
    TopPanel();
    explicit TopPanel(QWidget* parent);

private:
    void setupUI();
    void setCurDev(HIDDevInterface* dev);

private slots:
    void updateDevList(DEV_LIST_T* newList);
};