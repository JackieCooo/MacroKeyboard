#include "TopPanel.h"

TopPanel::TopPanel() {
    setupUI();
}

TopPanel::TopPanel(QWidget* parent) {
    this->setParent(parent);
    setupUI();
}

void TopPanel::setupUI() {
    hLayout = new QHBoxLayout(this);
    this->setLayout(hLayout);

    label = new QLabel("设备名：", this);
    label->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
    hLayout->addWidget(label);

    deviceList = new QComboBox(this);
    deviceList->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    deviceList->setObjectName("DeviceList");

    hLayout->addWidget(deviceList);
}
