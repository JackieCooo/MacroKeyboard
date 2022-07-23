#include "TopPanel.h"

/**
  * @brief 顶部栏类构造函数
  * @param 无
  * @retval 无
  */
TopPanel::TopPanel() {
    setupUI();
}

/**
  * @brief 顶部栏类构造函数
  * @param parent 父类
  * @retval 无
  */
TopPanel::TopPanel(QWidget* parent) {
    this->setParent(parent);
    setupUI();
}

/**
  * @brief 初始化UI
  * @param 无
  * @retval 无
  */
void TopPanel::setupUI() {
    hLayout = new QHBoxLayout(this);
    this->setLayout(hLayout);

    label = new QLabel("设备名：", this);
    label->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
    hLayout->addWidget(label);

    comboBox = new QComboBox(this);
    // 接收全局设备列表改变信号
    connect(GlobalEvent::getInstance(), SIGNAL(bridgeDevListChanged(DEV_LIST_T*)), this, SLOT(updateDevList(DEV_LIST_T*)));
    hLayout->addWidget(comboBox);
}

/**
  * @brief 更新设备列表
  * @param newList 新的设备列表
  * @retval 无
  */
void TopPanel::updateDevList(DEV_LIST_T* newList) {
    if (hidService == nullptr) return;

    comboBox->clear();
    for (auto i : *newList) {
        comboBox->addItem(i->getProductName());
    }

    if (newList->empty()) {
        hidService->setCurDev(nullptr);
    }
    else {
        hidService->setCurDev(newList->front());
    }
}
