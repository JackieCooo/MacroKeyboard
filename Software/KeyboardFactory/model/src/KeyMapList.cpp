#include "KeyMapList.h"

/**
  * @brief 获取PID
  * @param 无
  * @retval 返回PID
  */
uint16_t KeyMapList::getPid() const {
    return pid;
}

/**
  * @brief 设置PID
  * @param pid PID
  * @retval 无
  */
void KeyMapList::setPid(uint16_t pid) {
    this->pid = pid;
}

/**
  * @brief 获取用户键位表
  * @param 无
  * @retval 返回用户键位表
  */
QVector< QList<uint16_t> > &KeyMapList::getKeyMap() {
    return keyMap;
}

/**
  * @brief 设置用户键位表
  * @param keyMap 用户键位表
  * @retval 无
  */
void KeyMapList::setKeyMap(const QVector< QList<uint16_t> > &keyMap) {
    this->keyMap = keyMap;
}
