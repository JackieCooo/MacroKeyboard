#include "TransferTab.h"

/**
  * @brief 传输面板类构造函数
  * @param 无
  * @retval 无
  */
TransferTab::TransferTab() {
    setupUI();
}

/**
  * @brief 传输面板类构造函数
  * @param parent 父类
  * @retval 无
  */
TransferTab::TransferTab(QWidget* parent) {
    this->setParent(parent);
    setupUI();
}

/**
  * @brief 初始化UI
  * @param 无
  * @retval 无
  */
void TransferTab::setupUI() {
    vLayout = new QVBoxLayout();
    this->setLayout(vLayout);

    receiveLabel = new QLabel("接收: ", this);
    vLayout->addWidget(receiveLabel);

    receiveContent = new QTextBrowser(this);
    receiveContent->setReadOnly(true);
    vLayout->addWidget(receiveContent);

    sendLabel = new QLabel("发送: ", this);
    vLayout->addWidget(sendLabel);

    sendContent = new QTextBrowser(this);
    sendContent->setReadOnly(true);
    vLayout->addWidget(sendContent);

    // 接收全局数据接收成功信号，更新接收面板数据
    connect(GlobalEvent::getInstance(), SIGNAL(bridgeHidDataReceived(uint8_t*)), this, SLOT(updateReceiveInfo(uint8_t*)));
}

/**
  * @brief 更新接收信息
  * @param buf 接收数据数组
  * @retval 无
  */
void TransferTab::updateReceiveInfo(uint8_t *buf) {
    QString text;
    char tmpBuf[2];

    text = receiveContent->toPlainText();
//    qDebug("got text: %s", text.toStdString().c_str());
    for (int i = 0; i < MAX_RX_BUF_LEN; ++i) {
        itoa(buf[i], tmpBuf, 16);
        text += tmpBuf;
        text += ' ';
    }
    text += '\n';
//    qDebug("converted text: %s", text.toStdString().c_str());
    
    receiveContent->setText(text);
//    qDebug("set text");
}