#pragma once

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QSlider>

class TestTab : public QWidget {

private:
    QVBoxLayout* vLayout = nullptr;
    QPushButton* btn1 = nullptr;
    QPushButton* btn2 = nullptr;
    QPushButton* btn3 = nullptr;
    QSlider* slider1 = nullptr;
    QSlider* slider2 = nullptr;

public:
    TestTab();
    explicit TestTab(QWidget* parent);

private:
    void setupUI();

};

