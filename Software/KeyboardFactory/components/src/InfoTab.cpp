#include "InfoTab.h"

InfoTab::InfoTab() {
    setupUI();
}

InfoTab::InfoTab(QWidget *parent) {
    this->setParent(parent);
    setupUI();
}

void InfoTab::setupUI() {
    gLayout = new QGridLayout(this);
    this->setLayout(gLayout);

    vendorPanel = new InfoPanel(this, "厂商号: ");
    gLayout->addWidget(vendorPanel, 0, 0);

    productPanel = new InfoPanel(this, "产品号: ");
    gLayout->addWidget(productPanel, 0, 1);

    versionPanel = new InfoPanel(this, "版本号: ");
    gLayout->addWidget(versionPanel, 0, 2);

    moreInfo = new QLabel(this);
    moreInfo->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
    moreInfo->setText("test text");
    gLayout->addWidget(moreInfo, 1, 0, 1, 3);
}