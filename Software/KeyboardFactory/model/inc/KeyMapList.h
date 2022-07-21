#pragma once

#include <QVector>
#include <QList>

class KeyMapList {

private:
    uint16_t pid;
    QVector< QList<uint16_t> > keyMap;

public:
    KeyMapList() = default;
    [[nodiscard]] uint16_t getPid() const;
    void setPid(uint16_t pid);
    [[nodiscard]] QVector< QList<uint16_t> > &getKeyMap();
    void setKeyMap(const QVector< QList<uint16_t> > &keyMap);
};
