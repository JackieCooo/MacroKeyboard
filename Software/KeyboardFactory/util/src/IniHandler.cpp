#include "IniHandler.h"

/**
  * @brief 配置文件助手类构造函数
  * @param 无
  * @retval 无
  */
IniHandler::IniHandler() {
    productList = new QList<Product*>();
    initSysIni();
    loadConf();
    // 接收全局当前设备改变信号
    connect(GlobalEvent::getInstance(), SIGNAL(bridgeCurDevChanged(HIDDevInterface*)), this, SLOT(updateCurUserKeyMapList(HIDDevInterface*)));
}

/**
  * @brief 配置文件助手析构函数，释放内存
  * @param 无
  * @retval 无
  */
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

/**
  * @brief 初始化系统配置，检查本地配置文件完整性
  * @param 无
  * @retval 无
  */
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

/**
  * @brief 加载系统配置文件
  * @param 无
  * @retval 无
  */
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

/**
  * @brief 保存用户配置文件
  * @param 无
  * @retval 无
  */
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

/**
  * @brief 加载用户配置文件，从本地读入内存
  * @param pid 当前键盘PID
  * @retval 无
  */
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

/**
  * @brief 更新当前的用户键位映射表
  * @param newDev 新的HID设备
  * @retval 无
  */
void IniHandler::updateCurUserKeyMapList(HIDDevInterface *newDev) {
    loadUserConf(newDev->getProductId());
    emit userKeyMapListChanged(userKeyMapList);  // 发送用户键位映射表改变信号
}

/**
  * @brief 获取产品列表
  * @param 无
  * @retval 返回指向产品列表的指针
  */
QList<Product *> *IniHandler::getProductList() const {
    return productList;
}

/**
  * @brief 设置产品列表
  * @param productList 指向产品列表的指针
  * @retval 无
  */
void IniHandler::setProductList(QList<Product *> *productList) {
    IniHandler::productList = productList;
}

/**
  * @brief 获取用户键位映射表
  * @param 无
  * @retval 返回指向用户键位映射表的指针
  */
KeyMapList *IniHandler::getUserKeyMapList() const {
    return userKeyMapList;
}

/**
  * @brief 设置用户键位映射表
  * @param productList 指向用户键位映射表的指针
  * @retval 无
  */
void IniHandler::setUserKeyMapList(KeyMapList *userKeyMapList) {
    IniHandler::userKeyMapList = userKeyMapList;
}
