#include "TransferTab.h"

TransferTab::TransferTab() {
    setupUI();
}

TransferTab::TransferTab(QWidget* parent) {
    this->setParent(parent);
    setupUI();
}

void TransferTab::setupUI() {
    vLayout = new QVBoxLayout();
    this->setLayout(vLayout);

    receiveLabel = new QLabel("接收: ", this);
    vLayout->addWidget(receiveLabel);

    receiveContent = new QTextBrowser(this);
    vLayout->addWidget(receiveContent);

    sendLabel = new QLabel("发送: ", this);
    vLayout->addWidget(sendLabel);

    sendContent = new QTextBrowser(this);
    vLayout->addWidget(sendContent);
}