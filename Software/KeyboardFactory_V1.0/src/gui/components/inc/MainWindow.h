#pragma once

#include <QMainWindow>

#include "CentralWidget.h"

class MainWindow : public QMainWindow {

private:
    CentralWidget* centralWidget = nullptr;

public:
    MainWindow();

private:
    void setupUI();

};