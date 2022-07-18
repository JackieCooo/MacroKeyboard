#include "TopPanel.h"

TopPanel::TopPanel() {
    curDev = nullptr;
    setupUI();
}

TopPanel::TopPanel(QWidget* parent) {
    curDev = nullptr;
    this->setParent(parent);
    setupUI();
}

void TopPanel::setupUI() {
    hLayout = new QHBoxLayout(this);
    this->setLayout(hLayout);

    label = new QLabel("设备名：", this);
    label->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
    hLayout->addWidget(label);

    comboBox = new QComboBox(this);
    hidService = new HIDService();
    connect(hidService, SIGNAL(devListChanged(DEV_LIST_T *)), this, SLOT(updateDevList(DEV_LIST_T *)));
    hidService->start();
    hLayout->addWidget(comboBox);
}

void TopPanel::setCurDev(HIDDevInterface* dev) {
    if (dev == curDev) return;
    curDev = dev;
    char* tempBuf[16];
    itoa(curDev->getVendorId(), tempBuf);
    vendorPanel->setValueText();
}

void TopPanel::updateDevList(DEV_LIST_T* newList) {
    if (hidService == nullptr) return;

    comboBox->clear();
    for (auto i : *newList) {
        comboBox->addItem(i->getProductName());
    }

    if (newList->empty()) {
        setCurDev(nullptr);
    }
    else {
        setCurDev(newList->front());
    }
}
