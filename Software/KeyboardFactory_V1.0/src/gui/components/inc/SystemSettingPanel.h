#pragma once

#include <QWidget>

class SystemSettingPanel : public QWidget {

private:

public:
    SystemSettingPanel();
    explicit SystemSettingPanel(QWidget* parent);

private:
    void setupUI();

};