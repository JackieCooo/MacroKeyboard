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
            auto* key = new KeyBtn(keyboardLayout);
            keyboardLayout->addKeyBtn(*key, i, j);
        }
    }
    keyboardLayout->setLayoutMargin(10, 100, 10, 10);

    hLayout->addWidget(keyboardLayout);

    this->setLayout(hLayout);
}

