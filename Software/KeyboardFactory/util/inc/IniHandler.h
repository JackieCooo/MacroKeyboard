#pragma once

#include <QSettings>
#include <QDir>
#include <QObject>
#include <QList>
#include <QStringList>

#include "Product.h"
#include "UserConf.h"

using namespace std;

class IniHandler;

extern IniHandler* iniHandler;

class IniHandler : public QObject {

    Q_OBJECT

private:
    QList<Product*>* productList = nullptr;  // 产品列表
    QList<UserConf*>* userConfList = nullptr;  // 用户键位映射列表

public:
    IniHandler();
    ~IniHandler() override;
    void loadUserConf(uint16_t pid);

private:
    static void initSysIni();
    void loadConf();
    void saveUserConf();
};
