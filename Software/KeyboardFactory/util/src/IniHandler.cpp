#include "IniHandler.h"

IniHandler::IniHandler() {
    productList = new QList<Product*>();
    initSysIni();
    loadConf();
}

IniHandler::~IniHandler() {
    saveUserConf();
    for (auto i : *productList) {
        free(i);
    }
    free(productList);
    productList = nullptr;
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
    QSettings productIni("./ini/product.ini", QSettings::IniFormat);
    QStringList groups = productIni.childGroups();
    for (auto& i : groups) {
        Product* product = new Product();
        productIni.beginGroup(i);
        product->setName(i);
        product->setPid(productIni.value("pid").toUInt());
        product->setKeys(productIni.value("keys").toUInt());
        productIni.endGroup();
        productList->push_back(product);
    }
}

void IniHandler::saveUserConf() {

}

void IniHandler::loadUserConf(uint16_t pid) {
    if (userConfList == nullptr) {
        userConfList = new QList<UserConf*>();
    }

    QSettings userIni("./ini/user.ini", QSettings::IniFormat);
    auto Result1 = find_if(productList->begin(), productList->end(), [&](Product* tar){return tar->getPid() == pid;});
    if (Result1 == productList->end()) {
        return;
    }

    QString groupName = (*Result1)->getName();
    QStringList groups = userIni.childGroups();
    auto Result2 = find(groups.begin(), groups.end(), groupName);
    if (Result2 == groups.end()) {  // 找不到说明该设备为第一次使用，初始化键位映射表
        uint8_t keys = (*Result1)->getKeys();
        userIni.beginGroup(groupName);
        userIni.beginWriteArray("keyMap");
        for (int i = 0; i < keys; ++i) {
            userIni.setArrayIndex(i);
            userIni.setValue("key1", 0x00);
        }
        userIni.endArray();
        userIni.endGroup();
    }


}
