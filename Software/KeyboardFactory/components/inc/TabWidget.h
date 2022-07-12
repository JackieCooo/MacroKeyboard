#pragma once

#include <QTabWidget>
#include <QWidget>

#include "InfoTab.h"
#include "TransferTab.h"
#include "SettingTab.h"
#include "TestTab.h"

class TabWidget : public QTabWidget {

private:
    InfoTab* infoTab = nullptr;
    TransferTab* transferTab = nullptr;
    SettingTab* settingTab = nullptr;
    TestTab* testTab = nullptr;

public:
    TabWidget();
    explicit TabWidget(QWidget* parent);

private:
    void setupUI();
};

