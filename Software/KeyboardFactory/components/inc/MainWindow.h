#pragma once

#include <QMainWindow>
#include <QWidget>
#include <QVBoxLayout>

#include "TopPanel.h"
#include "TabWidget.h"
#include "HIDService.h"

class MainWindow : public QMainWindow {

private:
    QWidget* mainFrame = nullptr;
    QVBoxLayout* vLayout = nullptr;
    TopPanel* topPanel = nullptr;
    TabWidget* tabWidget = nullptr;

    HIDService* hidService = nullptr;

public:
    MainWindow();
    [[nodiscard]] HIDService *getHidService() const;

private:
    void setupUI();

};
