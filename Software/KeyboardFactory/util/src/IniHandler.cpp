#include "IniHandler.h"

IniHandler::IniHandler() {
    productList = new QList<Product*>();
    initSysIni();
    loadConf();
    // 接收全局当前设备改变信号
    connect(GlobalEvent::getInstance(), SIGNAL(bridgeCurDevChanged(HIDDevInterface*)), this, SLOT(updateCurUserKeyMapList(HIDDevInterface*)));
}

IniHandler::~IniHandler() {
    saveUserConf();

    for (auto i : *productList) {
        delete i;
    }
    delete productList;
    productList = nullptr;

    delete userKeyMapList;
    userKeyMapList = nullptr;
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
        auto* product = new Product();
        productIni.beginGroup(i);
        product->setName(i);
        product->setPid(productIni.value("pid").toUInt());
        product->setKeys(productIni.value("keys").toUInt());
        productIni.endGroup();
        productList->push_back(product);
    }
}

void IniHandler::saveUserConf() {
    if (userKeyMapList == nullptr) {
        return;
    }

    QSettings userIni("./ini/user.ini", QSettings::IniFormat);

    // 获取键盘名
    auto Result = find_if(productList->begin(), productList->end(), [&](Product* tar){return tar->getPid() == userKeyMapList->getPid();});
    if (Result == productList->end()) {
        return;
    }
    QString groupName = (*Result)->getName();
    uint8_t keys = (*Result)->getKeys();

    userIni.beginGroup(groupName);
    userIni.beginWriteArray("keyMap");
    auto keyMap = userKeyMapList->getKeyMap();
    QString keyNum = "key";
    for (int i = 0; i < keys; ++i) {  // 遍历每一个键位
        userIni.setArrayIndex(i);
        uint8_t index = 1;
        for (auto j : keyMap[i]) {  // 遍历每一个组合键中的键
            QChar ch(index + '0');
            keyNum += ch;
            userIni.setValue(keyNum , j);
            keyNum.remove(ch);
            ++index;
        }
    }
    userIni.endArray();
    userIni.endGroup();
}

void IniHandler::loadUserConf(uint16_t pid) {
    if (userKeyMapList == nullptr) {
        userKeyMapList = new KeyMapList();
    }
    else {
        free(userKeyMapList);
        userKeyMapList = new KeyMapList();
    }
    userKeyMapList->setPid(pid);

    QSettings userIni("./ini/user.ini", QSettings::IniFormat);
    // 由PID获取键盘名
    auto Result1 = find_if(productList->begin(), productList->end(), [&](Product* tar){return tar->getPid() == pid;});
    if (Result1 == productList->end()) {
        return;
    }

    QString groupName = (*Result1)->getName();  // 当前键盘名
    QStringList groups = userIni.childGroups();  // 用户所有的键盘
    uint8_t keys = (*Result1)->getKeys();  // 键盘总键数
    auto keyMap = userKeyMapList->getKeyMap();
    keyMap.resize(keys);
    auto Result2 = find(groups.begin(), groups.end(), groupName);
    if (Result2 == groups.end()) {  // 配置文件找不到说明该设备，说明为第一次使用，初始化键位映射表
        for (int i = 0; i < keys; ++i) {
            keyMap[i].push_back(0x00);
            keyMap[i].push_back(0x00);
        }
    }
    else {  // 从本地配置文件读取键位映射表
        userIni.beginGroup(groupName);
        userIni.beginReadArray("keyMap");
        for (int i = 0; i < keys; ++i) {
            userIni.setArrayIndex(i);
            for (auto& j : userIni.allKeys()) {
                keyMap[i].push_back(userIni.value(j).toUInt());
            }
        }
        userIni.endArray();
        userIni.endGroup();
    }
    userKeyMapList->setKeyMap(keyMap);
}

void IniHandler::updateCurUserKeyMapList(HIDDevInterface *newDev) {
    loadUserConf(newDev->getProductId());
    emit userKeyMapListChanged(userKeyMapList);  // 发送用户键位映射表改变信号
}

QList<Product *> *IniHandler::getProductList() const {
    return productList;
}

void IniHandler::setProductList(QList<Product *> *productList) {
    IniHandler::productList = productList;
}

KeyMapList *IniHandler::getUserKeyMapList() const {
    return userKeyMapList;
}

void IniHandler::setUserKeyMapList(KeyMapList *userKeyMapList) {
    IniHandler::userKeyMapList = userKeyMapList;
}
