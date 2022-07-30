#include "StyleStackWidget.h"

StyleStackWidget::StyleStackWidget() {
    setupUI();
}

StyleStackWidget::StyleStackWidget(QWidget *parent) : QStackedWidget(parent) {
    setupUI();
}

void StyleStackWidget::setupUI() {
    keyboardModifyPanel = new KeyboardModifyPanel();
    this->addWidget(keyboardModifyPanel);

    systemSettingPanel = new SystemSettingPanel();
    this->addWidget(systemSettingPanel);

    this->setCurrentIndex(0);
}