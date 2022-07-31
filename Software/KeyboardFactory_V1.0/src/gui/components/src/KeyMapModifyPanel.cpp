#include "KeyMapModifyPanel.h"

KeyMapModifyPanel::KeyMapModifyPanel() {
    setupUI();
}

KeyMapModifyPanel::KeyMapModifyPanel(QWidget *parent) : QWidget(parent) {
    setupUI();
}

void KeyMapModifyPanel::setupUI() {
    vLayout = new QVBoxLayout(this);

    label = new QLabel("键位映射", this);
    label->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    label->setFont(QFont("微软雅黑", 16));
    vLayout->addWidget(label);

    this->setLayout(vLayout);
}