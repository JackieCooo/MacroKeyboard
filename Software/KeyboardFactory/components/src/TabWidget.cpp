#include "TabWidget.h"

TabWidget::TabWidget() {
    setupUI();
}

TabWidget::TabWidget(QWidget *parent) {
    this->setParent(parent);
    setupUI();
}

void TabWidget::setupUI() {
    infoTab = new InfoTab();
    this->addTab(infoTab, "基本信息");

    transferTab = new TransferTab();
    this->addTab(transferTab, "传输信息");

    settingTab = new SettingTab();
    this->addTab(settingTab, "键位设置");

    this->setCurrentIndex(0);
}