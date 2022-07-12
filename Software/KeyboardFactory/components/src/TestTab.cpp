#include "TestTab.h"

TestTab::TestTab() {
    setupUI();
}

TestTab::TestTab(QWidget *parent) {
    this->setParent(parent);
    setupUI();
}

void TestTab::setupUI() {
    vLayout = new QVBoxLayout(this);
    this->setLayout(vLayout);

    slider1 = new QSlider(this);
    slider1->setOrientation(Qt::Horizontal);
    vLayout->addWidget(slider1);

    slider2 = new QSlider(this);
    slider2->setOrientation(Qt::Horizontal);
    vLayout->addWidget(slider2);

    btn1 = new QPushButton("复制", this);
    vLayout->addWidget(btn1);

    btn2 = new QPushButton("粘贴", this);
    vLayout->addWidget(btn2);

    btn3 = new QPushButton("剪切", this);
    vLayout->addWidget(btn3);

}