#include "KeyMapList.h"

unsigned short KeyMapList::getPid() const {
    return pid;
}

void KeyMapList::setPid(unsigned short pid) {
    this->pid = pid;
}

QVector< QList<uint16_t> > &KeyMapList::getKeyMap() {
    return keyMap;
}

void KeyMapList::setKeyMap(const QVector< QList<uint16_t> > &keyMap) {
    this->keyMap = keyMap;
}
