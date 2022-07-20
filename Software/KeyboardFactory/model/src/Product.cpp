#include "Product.h"

const QString &Product::getName() const {
    return name;
}

void Product::setName(const QString &name) {
    this->name = name;
}

uint16_t Product::getPid() const {
    return pid;
}

void Product::setPid(uint16_t pid) {
    this->pid = pid;
}

Product::Product(const QString &name, uint16_t pid) : name(name), pid(pid) {}

uint8_t Product::getKeys() const {
    return keys;
}

void Product::setKeys(uint8_t keys) {
    this->keys = keys;
}
