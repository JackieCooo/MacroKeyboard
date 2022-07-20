#include "Product.h"

const QString &Product::getName() const {
    return name;
}

void Product::setName(const QString &name) {
    this->name = name;
}

int Product::getPid() const {
    return pid;
}

void Product::setPid(int pid) {
    this->pid = pid;
}

Product::Product(const QString &name, int pid) : name(name), pid(pid) {}
