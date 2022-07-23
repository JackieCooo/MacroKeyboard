#include "InfoTab.h"

/**
  * @brief 信息标签页类构造函数
  * @param 无
  * @retval 无
  */
InfoTab::InfoTab() {
    setupUI();
}

/**
  * @brief 信息标签页类构造函数
  * @param parent 父类
  * @retval 无
  */
InfoTab::InfoTab(QWidget *parent) {
    this->setParent(parent);
    setupUI();
}

/**
  * @brief 初始化UI
  * @param 无
  * @retval 无
  */
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

/**
  * @brief 更新当前HID设备
  * @param newDev 新的HID设备
  * @retval 无
  */
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
    tmpStr += "特征报告长度: ";
    itoa(newDev->getFeatureReportByteLength(), tmpBuf, 10);
    tmpStr += tmpBuf;
    tmpStr += '\n';
    tmpStr += "输出报告长度: ";
    itoa(newDev->getOutputReportByteLength(), tmpBuf, 10);
    tmpStr += tmpBuf;
    tmpStr += '\n';
    tmpStr += "输入报告长度: ";
    itoa(newDev->getInputReportByteLength(), tmpBuf, 10);
    tmpStr += tmpBuf;
    tmpStr += '\n';
    moreInfo->setText(tmpStr);
}