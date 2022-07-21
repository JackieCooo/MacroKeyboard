#pragma once

#include <QVector>
#include <QString>

class VirtualKeyList;

extern VirtualKeyList* virtualKeyList;

class VirtualKeyList : public QVector<QString> {

public:
    VirtualKeyList();
    uint8_t keyCode(const QString& name);
    QString& keyName(uint8_t keyCode);

private:
    void setupList();

};