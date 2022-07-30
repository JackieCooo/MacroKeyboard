#include "Menu.h"

Menu::Menu() {
    setupUI();
    setupListener();
}

Menu::Menu(QWidget *parent) : QWidget(parent) {
    setupUI();
    setupListener();
}

void Menu::setupUI() {
    vLayout = new QVBoxLayout(this);
    vLayout->setContentsMargins(0, 0, 0, 0);

    toolBtn = new MenuToolBtn(this, "../src/gui/icons/List_Default_30px.png", "../src/gui/icons/List_Hover_30px.png");
    vLayout->addWidget(toolBtn);

    auto* keyboardBtn = new MenuBtn(this, "../src/gui/icons/Keyboard_Default_30px.png", "../src/gui/icons/Keyboard_Selected_30px.png", "键盘设置");
    keyboardBtn->setChecked(true);
    vLayout->addWidget(keyboardBtn);
    menuBtnList.push_back(keyboardBtn);

    auto* settingBtn = new MenuBtn(this, "../src/gui/icons/Setting_Default_30px.png", "../src/gui/icons/Setting_Selected_30px.png", "系统设置");
    vLayout->addWidget(settingBtn);

    spacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
    vLayout->addItem(spacer);
    menuBtnList.push_back(settingBtn);

    this->setLayout(vLayout);

    buttonGroup = new QButtonGroup();
    buttonGroup->setExclusive(true);
    for (auto i : menuBtnList) {
        buttonGroup->addButton(i);
    }
}

void Menu::setupListener() {
    for (auto i : menuBtnList) {
        connect(toolBtn, SIGNAL(clicked(bool)), i, SLOT(stateChange()));
    }
}
