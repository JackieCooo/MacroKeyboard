#include "InfoPanel.h"

InfoPanel::InfoPanel() {
    setupUI();
}

InfoPanel::InfoPanel(QWidget *parent) {
    this->setParent(parent);
    setupUI();
}

InfoPanel::InfoPanel(QWidget *parent, const QString& text) {
    this->setParent(parent);
    this->labelText = text;
    setupUI();
}

void InfoPanel::setupUI() {
    hLayout = new QHBoxLayout();
    this->setLayout(hLayout);

    this->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);

    label = new QLabel(labelText, this);
    label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
    hLayout->addWidget(label);

    value = new QLabel(valueText, this);
    hLayout->addWidget(value);
}

const QString &InfoPanel::getLabelText() const {
    return labelText;
}

void InfoPanel::setLabelText(const QString &text) {
    InfoPanel::labelText = text;
}

const QString &InfoPanel::getValueText() const {
    return valueText;
}

void InfoPanel::setValueText(const QString &text) {
    InfoPanel::valueText = text;
}
