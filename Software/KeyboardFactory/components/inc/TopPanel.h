#pragma once

#include <QWidget>
#include <QLabel>
#include <QComboBox>
#include <QHBoxLayout>
#include <QSizePolicy>
#include <QDebug>

#include "HidService.h"
#include "GlobalEvent.h"

class TopPanel : public QWidget {

    Q_OBJECT

private:
    QHBoxLayout* hLayout = nullptr;
    QLabel* label = nullptr;
    QComboBox* comboBox = nullptr;

public:
    TopPanel();
    explicit TopPanel(QWidget* parent);

private:
    void setupUI();

private slots:
    void updateDevList(DEV_LIST_T* newList);

signals:
    void curDevChanged(HIDDevInterface* newDev);
};