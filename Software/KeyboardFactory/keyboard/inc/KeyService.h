#pragma once

#include <QObject>
#include <QVector>
#include <QList>
#include <windows.h>

#include "GlobalEvent.h"
#include "IniHandler.h"
#include "KeyMapList.h"

#define MAX_INPUT_NUM 6  // 组合键最大键位数
#define MAX_INPUT_ARR_SIZE (2 * MAX_INPUT_NUM)  // INPUT数组最大大小

class KeyService;

extern KeyService* keyService;

class KeyService : public QObject{

    Q_OBJECT

private:
    KeyMapList* keyMapList = nullptr;  // 用户键位映射表
    INPUT inputs[MAX_INPUT_ARR_SIZE] = {};  // 模拟输入键位

public:
    KeyService();
    void executeComboKey(uint8_t keyNum);

private slots:
    void parseDataAndSend(uint8_t* rxBuf);
    void registerKeyMap(KeyMapList* keyMapList);
};
