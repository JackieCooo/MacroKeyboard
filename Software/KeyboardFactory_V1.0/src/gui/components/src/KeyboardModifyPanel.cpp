#include "KeyboardModifyPanel.h"

KeyboardModifyPanel::KeyboardModifyPanel() {
    setupUI();
}

KeyboardModifyPanel::KeyboardModifyPanel(QWidget *parent) : QWidget(parent) {
    setupUI();
}

void KeyboardModifyPanel::setupUI() {
    hLayout = new QHBoxLayout(this);

    keyboardLayout = new KeyboardLayout(this, 300, 400);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            QChar ch((3 * i + j + 1) + '0');
            auto* key = new KeyBtn(keyboardLayout, QString(ch));
            keyboardLayout->addKeyBtn(*key, i, j);
        }
    }
    keyboardLayout->setLayoutMargin(10, 100, 10, 10);
    hLayout->addWidget(keyboardLayout);

    keyMapModifyPanel = new KeyMapModifyPanel(this);
    hLayout->addWidget(keyMapModifyPanel);

    this->setLayout(hLayout);
}

