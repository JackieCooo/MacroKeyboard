#pragma once

#include <QSettings>
#include <QDir>
#include <QObject>
#include <QList>

#include "Product.h"

class IniHandler;

extern IniHandler* iniHandler;

class IniHandler : public QObject {

    Q_OBJECT

private:
    QList<Product> productList;  // 产品列表

public:
    IniHandler();

private:
    static void initSysIni();
    void loadConf();
};
