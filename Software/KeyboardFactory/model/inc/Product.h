#pragma once

#include <QString>

class Product {

private:
    QString name;
    uint16_t pid;
    uint8_t keys;

public:
    Product() = default;
    Product(const QString &name, uint16_t pid);
    [[nodiscard]] const QString &getName() const;
    void setName(const QString &name);
    [[nodiscard]] uint16_t getPid() const;
    void setPid(uint16_t pid);
    [[nodiscard]] uint8_t getKeys() const;
    void setKeys(uint8_t keys);

};
