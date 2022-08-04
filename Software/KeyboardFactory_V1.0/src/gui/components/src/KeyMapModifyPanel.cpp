#include "KeyMapModifyPanel.h"

KeyMapModifyPanel::KeyMapModifyPanel() {
    setupUI();
}

KeyMapModifyPanel::KeyMapModifyPanel(QWidget *parent) : QWidget(parent) {
    setupUI();
}

void KeyMapModifyPanel::setupUI() {
    vLayout = new QVBoxLayout(this);

    label = new QLabel("键位映射", this);
    label->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    label->setFont(QFont("微软雅黑", 16));
    vLayout->addWidget(label);

    comboBox = new StyleComboBox(this);
    for (int i = 0; i < 15; ++i) {
        comboBox->addItem(QString("test%1").arg(i));
    }
    vLayout->addWidget(comboBox);

    spacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
    vLayout->addItem(spacer);

    this->setLayout(vLayout);
}