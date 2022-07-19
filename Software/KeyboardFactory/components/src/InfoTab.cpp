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
    gLayout->addWidget(moreInfo, 1, 0, 1, 3);

    // 接收全局当前设备改变信号
    connect(GlobalEvent::getInstance(), SIGNAL(bridgeCurDevChanged(HIDDevInterface*)), this, SLOT(updateCurDevInfo(HIDDevInterface*)));
}

void InfoTab::updateCurDevInfo(HIDDevInterface *newDev) {
    if (newDev == nullptr) {
//        qDebug("newDev == nullptr");
        vendorPanel->setValueText(nullptr);
        productPanel->setValueText(nullptr);
        versionPanel->setValueText(nullptr);
        moreInfo->setText(nullptr);
        return;
    }

//    qDebug("newDev != nullptr");
    char tmpBuf[16];
    QString tmpStr;

    itoa(newDev->getVendorId(), tmpBuf, 10);
    tmpStr = tmpBuf;
    vendorPanel->setValueText(tmpStr);

    itoa(newDev->getProductId(), tmpBuf, 10);
    tmpStr = tmpBuf;
    productPanel->setValueText(tmpStr);

    itoa(newDev->getVersionNumber(), tmpBuf, 10);
    tmpStr = tmpBuf;
    versionPanel->setValueText(tmpStr);

    tmpStr.clear();
    tmpStr += "FeatureReportLength: ";
    itoa(newDev->getFeatureReportByteLength(), tmpBuf, 10);
    tmpStr += tmpBuf;
    tmpStr += '\n';
    tmpStr += "OutputReportLength: ";
    itoa(newDev->getOutputReportByteLength(), tmpBuf, 10);
    tmpStr += tmpBuf;
    tmpStr += '\n';
    tmpStr += "InputReportLength: ";
    itoa(newDev->getInputReportByteLength(), tmpBuf, 10);
    tmpStr += tmpBuf;
    tmpStr += '\n';
    moreInfo->setText(tmpStr);
}