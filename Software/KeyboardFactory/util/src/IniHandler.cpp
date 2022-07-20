#include "IniHandler.h"

IniHandler::IniHandler() {
    initSysIni();
}

void IniHandler::initSysIni() {
    QDir iniDir("./ini");

    // 新建ini文件夹存放本地数据
    if (!iniDir.exists()) {
        QDir curDir(QDir::currentPath());
        curDir.mkdir("./ini");
    }

    // 新建ini文件保存产品信息
    if (!iniDir.exists("./product.ini")) {
        QSettings productIni("./ini/product.ini", QSettings::IniFormat);
        productIni.beginGroup("MacroV0.1");
        productIni.setValue("keys", 2);
        productIni.setValue("pid", 22352);
        productIni.endGroup();
    }

}

void IniHandler::loadConf() {

}
