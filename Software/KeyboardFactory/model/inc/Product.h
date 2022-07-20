#pragma once

#include <QString>

class Product {

private:
    QString name;
    int pid;

public:
    Product() = default;
    Product(const QString &name, int pid);
    [[nodiscard]] const QString &getName() const;
    void setName(const QString &name);
    [[nodiscard]] int getPid() const;
    void setPid(int pid);
};
