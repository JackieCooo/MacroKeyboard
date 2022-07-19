#include "InfoPanel.h"

InfoPanel::InfoPanel() {
    setupUI(nullptr);
}

InfoPanel::InfoPanel(QWidget *parent) {
    this->setParent(parent);
    setupUI(nullptr);
}

InfoPanel::InfoPanel(QWidget *parent, const QString& text = nullptr) {
    this->setParent(parent);
    setupUI(text);
}

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

void InfoPanel::setValueText(const QString &text) {
    value->setText(text);
}
