#pragma once

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QSlider>

#include "KeyService.h"

class TestTab : public QWidget {

    Q_OBJECT

private:
    QVBoxLayout* vLayout = nullptr;
    QPushButton* btn1 = nullptr;
    QPushButton* btn2 = nullptr;
    QPushButton* btn3 = nullptr;

    KeyService* keyService = nullptr;

public:
    TestTab();
    explicit TestTab(QWidget* parent);

private:
    void setupUI();

private slots:
    void key1Pressed();
    void volumeUp();

};

