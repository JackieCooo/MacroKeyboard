#pragma once

#include <QStackedWidget>
#include <QWidget>

#include "KeyboardModifyPanel.h"
#include "SystemSettingPanel.h"

class StyleStackWidget : public QStackedWidget {

private:
    KeyboardModifyPanel* keyboardModifyPanel = nullptr;
    SystemSettingPanel* systemSettingPanel = nullptr;

public:
    StyleStackWidget();
    explicit StyleStackWidget(QWidget* parent);

private:
    void setupUI();

};