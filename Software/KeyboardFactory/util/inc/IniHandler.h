#pragma once

#include <QSettings>
#include <QDir>
#include <QObject>
#include <QList>
#include <QStringList>
#include <QString>
#include <QChar>

#include "Product.h"
#include "KeyMapList.h"
#include "HIDDevInterface.h"
#include "GlobalEvent.h"

using namespace std;

class IniHandler;

extern IniHandler* iniHandler;

class IniHandler : public QObject {

    Q_OBJECT

private:
    QList<Product*>* productList = nullptr;  // 产品列表
    KeyMapList* userKeyMapList = nullptr;  // 用户键位映射列表

public:
    IniHandler();
    ~IniHandler() override;
    void loadUserConf(uint16_t pid);
    QList<Product *> *getProductList() const;
    void setProductList(QList<Product *> *productList);
    KeyMapList *getUserKeyMapList() const;
    void setUserKeyMapList(KeyMapList *userKeyMapList);

private:
    static void initSysIni();
    void loadConf();
    void saveUserConf();

signals:
    void userKeyMapListChanged(KeyMapList* curKeyMap);

private slots:
    void updateCurUserKeyMapList(HIDDevInterface* newDev);
};
