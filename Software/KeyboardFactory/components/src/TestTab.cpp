#include "TestTab.h"

TestTab::TestTab() {
    keyService = new KeyService();
    setupUI();
}

TestTab::TestTab(QWidget *parent) {
    keyService = new KeyService();
    this->setParent(parent);
    setupUI();
}

void TestTab::setupUI() {
    vLayout = new QVBoxLayout(this);
    this->setLayout(vLayout);

    btn1 = new QPushButton("打开文件浏览器", this);
    connect(btn1, SIGNAL(clicked(bool)), this, SLOT(key1Pressed()));
    vLayout->addWidget(btn1);

    btn2 = new QPushButton("增大音量", this);
    connect(btn2, SIGNAL(clicked(bool)), this, SLOT(volumeUp()));
    vLayout->addWidget(btn2);

    btn3 = new QPushButton("剪切", this);
    vLayout->addWidget(btn3);

}

void TestTab::key1Pressed() {
    keyService->comboKey1Pressed();
}

void TestTab::volumeUp() {
    keyService->higherVolume();
}
