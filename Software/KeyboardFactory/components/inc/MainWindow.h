#pragma once

#include <QMainWindow>
#include <QWidget>
#include <QVBoxLayout>
#include <QCloseEvent>
#include <csignal>

#include "TopPanel.h"
#include "TabWidget.h"

class MainWindow : public QMainWindow {

private:
    QWidget* mainFrame = nullptr;
    QVBoxLayout* vLayout = nullptr;
    TopPanel* topPanel = nullptr;
    TabWidget* tabWidget = nullptr;

protected:
    void closeEvent(QCloseEvent *event) override;

public:
    MainWindow();

private:
    void setupUI();

};
