#include "UserConf.h"

unsigned short UserConf::getPid() const {
    return pid;
}

void UserConf::setPid(unsigned short pid) {
    this->pid = pid;
}

const QList<unsigned short> &UserConf::getKeyMap() const {
    return keyMap;
}

void UserConf::setKeyMap(const QList<unsigned short> &keyMap) {
    this->keyMap = keyMap;
}
