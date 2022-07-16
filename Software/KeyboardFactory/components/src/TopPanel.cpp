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
    connect(, SIGNAL())
    hLayout->addWidget(deviceList);
}

void TopPanel::setHIDService(HIDService *service) {
    this->hidService = service;
}

void TopPanel::updateDeviceList(DEV_LIST_T *newList) {

}
