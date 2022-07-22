#include "SettingTab.h"

uint8_t regularKeys[] = {  // 定义一些常用的键位
        0, 8, 9, 12, 13, 16, 17, 18, 19, 20, 27,
        32, 33, 34, 35, 36, 37, 38, 39, 40, 44,
        45, 46, 48, 49, 50, 51, 52, 53, 54, 55,
        56, 57, 65, 66, 67, 68, 69, 70, 71, 72,
        73, 74, 75, 76, 77, 78, 79, 80, 81, 82,
        83, 84, 85, 86, 87, 88, 89, 90, 95, 96,
        97, 98, 99, 100, 101, 102, 103, 104, 105,
        106, 107, 108, 109, 110, 111, 112, 113, 114, 115,
        116, 117, 118, 119, 120, 121, 122, 123, 144, 145,
        173, 174, 175
};

SettingTab::SettingTab() {
    setupUI();
}

SettingTab::SettingTab(QWidget *parent) {
    this->setParent(parent);
    setupUI();
}

void SettingTab::setupUI() {
    gLayout = new QGridLayout(this);
    this->setLayout(gLayout);

    keyList = new QListWidget(this);
    keyList->setMaximumWidth(250);
    // 接收用户键位映射表改变信号，更新用户键位映射表
    connect(iniHandler, SIGNAL(userKeyMapListChanged(KeyMapList*)), this, SLOT(updateKeyList(KeyMapList*)));
    gLayout->addWidget(keyList, 0, 0, 2, 1);

    keyDefinePanel = new QWidget(this);
    hLayout = new QHBoxLayout(keyDefinePanel);
    keyDefinePanel->setLayout(hLayout);

    label = new QLabel("键位映射: ", this);
    label->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
    hLayout->addWidget(label);

    firstKey = new QComboBox(keyDefinePanel);
    for (auto i : regularKeys) {
        firstKey->addItem(virtualKeyList->keyName(i));
    }
    hLayout->addWidget(firstKey);

    plusLabel = new QLabel("+", keyDefinePanel);
    plusLabel->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
    hLayout->addWidget(plusLabel);

    secondKey = new QComboBox(keyDefinePanel);
    for (auto i : regularKeys) {
        secondKey->addItem(virtualKeyList->keyName(i));
    }
    hLayout->addWidget(secondKey);

    // 接收键位表当前行改变信号，更新设置面板按键显示
    connect(keyList, SIGNAL(currentRowChanged(int)), this, SLOT(updateKeySettingPanel(int)));

    gLayout->addWidget(keyDefinePanel, 0, 1);

    okBtn = new QPushButton("确定", this);
    // 接收按钮点击事件，设置新的键位映射
    connect(okBtn, SIGNAL(clicked(bool)), this, SLOT(setNewKeyMap()));
    gLayout->addWidget(okBtn, 1, 1);
}

void SettingTab::updateKeyList(KeyMapList *curKeyMap) {
    keyList->clear();
    auto keysNum = curKeyMap->getKeyMap().size();
    QString tmpStr = "key";
    for (int i = 1; i <= keysNum; ++i) {
        QChar ch(i + '0');
        tmpStr += ch;
        keyList->addItem(tmpStr);
        tmpStr.remove(ch);
    }
    keyList->setCurrentRow(0);
}

void SettingTab::updateKeySettingPanel(int curRow) {
//    qDebug("curRow: %d", curRow);
    auto keyMap = iniHandler->getUserKeyMapList()->getKeyMap();
    firstKey->setCurrentText(virtualKeyList->keyName(keyMap[curRow][0]));
    secondKey->setCurrentText(virtualKeyList->keyName(keyMap[curRow][1]));
}

void SettingTab::setNewKeyMap() {
    auto& keyMap = iniHandler->getUserKeyMapList()->getKeyMap();
    int curRow = keyList->currentRow();
    keyMap[curRow][0] = virtualKeyList->keyCode(firstKey->currentText());
    keyMap[curRow][1] = virtualKeyList->keyCode(secondKey->currentText());
}
