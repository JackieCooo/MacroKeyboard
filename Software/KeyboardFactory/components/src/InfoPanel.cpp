#include "InfoPanel.h"

/**
  * @brief 信息面板类构造函数
  * @param 无
  * @retval 无
  */
InfoPanel::InfoPanel() {
    setupUI(nullptr);
}

/**
  * @brief 信息面板类构造函数
  * @param parent 父类
  * @retval 无
  */
InfoPanel::InfoPanel(QWidget *parent) {
    this->setParent(parent);
    setupUI(nullptr);
}

/**
  * @brief 信息面板类构造函数
  * @param parent 父类
  * @param text 标题
  * @retval 无
  */
InfoPanel::InfoPanel(QWidget *parent, const QString& text = nullptr) {
    this->setParent(parent);
    setupUI(text);
}

/**
  * @brief 初始化UI
  * @param text 标题
  * @retval 无
  */
void InfoPanel::setupUI(const QString& text = nullptr) {
    hLayout = new QHBoxLayout();
    this->setLayout(hLayout);

    this->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);

    label = new QLabel(text, this);
    label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
    hLayout->addWidget(label);

    value = new QLabel(this);
    hLayout->addWidget(value);
}

/**
  * @brief 设置标题
  * @param text 标题
  * @retval 无
  */
void InfoPanel::setValueText(const QString &text) {
    if (this->value != nullptr) this->value->setText(text);
}
