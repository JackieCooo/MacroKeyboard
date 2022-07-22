#include "KeyService.h"

KeyService::KeyService() {
    // 接收用户键位表改变信号，注册新的按键映射表
    connect(iniHandler, SIGNAL(userKeyMapListChanged(KeyMapList*)), this, SLOT(registerKeyMap(KeyMapList*)));
    // 接收数据接收成功信号，解码并执行组合键
    connect(GlobalEvent::getInstance(), SIGNAL(bridgeHidDataReceived(uint8_t*)), this, SLOT(parseDataAndSend(uint8_t*)));
}

void KeyService::registerKeyMap(KeyMapList *keyMapList) {
    this->keyMapList = keyMapList;
}

void KeyService::parseDataAndSend(uint8_t *rxBuf) {
    executeComboKey(rxBuf[0] - 1);
}

void KeyService::executeComboKey(uint8_t keyNum) {
    auto allKeyCodes = (keyMapList->getKeyMap())[keyNum];
    uint8_t keys = allKeyCodes.size();  // 获取组合键的键数
    uint8_t j = 0, k = 2 * keys - 1;
    // 构造发送信息
    for (auto i : allKeyCodes) {
        inputs[j].type = INPUT_KEYBOARD;
        inputs[j].ki.wVk = i;

        inputs[k].type = INPUT_KEYBOARD;
        inputs[k].ki.wVk = i;
        inputs[k].ki.dwFlags = KEYEVENTF_KEYUP;

        ++j;
        --k;
    }

    SendInput(2 * keys, inputs, sizeof(INPUT));  // 向系统发送虚拟键位
}
