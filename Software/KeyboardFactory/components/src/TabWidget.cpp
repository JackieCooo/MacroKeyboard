#include "TabWidget.h"

/**
  * @brief 标签页面板类构造函数
  * @param 无
  * @retval 无
  */
TabWidget::TabWidget() {
    setupUI();
}

/**
  * @brief 标签页面板类构造函数
  * @param parent 父类
  * @retval 无
  */
TabWidget::TabWidget(QWidget *parent) {
    this->setParent(parent);
    setupUI();
}

/**
  * @brief 初始化UI
  * @param 无
  * @retval 无
  */
void TabWidget::setupUI() {
    infoTab = new InfoTab();
    this->addTab(infoTab, "基本信息");

    transferTab = new TransferTab();
    this->addTab(transferTab, "传输信息");

    settingTab = new SettingTab();
    this->addTab(settingTab, "键位设置");

    this->setCurrentIndex(0);
}