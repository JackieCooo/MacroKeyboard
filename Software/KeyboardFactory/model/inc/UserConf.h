#pragma once

#include <cstdint>
#include <QVector>

class UserConf {

private:
    uint16_t pid;
    QVector<uint16_t> keyMap;

public:
    UserConf() = default;
    [[nodiscard]] uint16_t getPid() const;
    void setPid(uint16_t pid);
    [[nodiscard]] const QVector<uint16_t> &getKeyMap() const;
    void setKeyMap(const QVector<uint16_t> &keyMap);
};