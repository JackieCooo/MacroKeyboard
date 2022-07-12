#include "SettingTab.h"

SettingTab::SettingTab() {
    setupUI();
}

SettingTab::SettingTab(QWidget *parent) {
    this->setParent(parent);
    setupUI();
}

void SettingTab::setupUI() {
    gLayout = new QGridLayout(this);
    this->setLayout(gLayout);

    keyList = new QListWidget(this);
    keyList->setMaximumWidth(250);
    gLayout->addWidget(keyList, 0, 0, 2, 1);

    keyDefinePanel = new QWidget(this);
    hLayout = new QHBoxLayout(keyDefinePanel);
    keyDefinePanel->setLayout(hLayout);

    label = new QLabel("键位映射: ", this);
    label->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
    hLayout->addWidget(label);

    firstKey = new QComboBox(keyDefinePanel);
    hLayout->addWidget(firstKey);

    plusLabel = new QLabel("+", keyDefinePanel);
    plusLabel->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
    hLayout->addWidget(plusLabel);

    secondKey = new QComboBox(keyDefinePanel);
    hLayout->addWidget(secondKey);

    gLayout->addWidget(keyDefinePanel, 0, 1);

    okBtn = new QPushButton("确定", this);
    gLayout->addWidget(okBtn, 1, 1);
}