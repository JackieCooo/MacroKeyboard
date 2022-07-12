#pragma once

#include <QMainWindow>
#include <QWidget>
#include <QVBoxLayout>

#include "TopPanel.h"
#include "TabWidget.h"

class MainWindow : public QMainWindow {

private:
    QWidget* mainFrame = nullptr;
    QVBoxLayout* vLayout = nullptr;
    TopPanel* topPanel = nullptr;
    TabWidget* tabWidget = nullptr;

public:
    MainWindow();

private:
    void setupUI();

};
