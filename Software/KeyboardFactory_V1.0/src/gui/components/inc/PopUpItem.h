#pragma once

#include <QAbstractButton>

class PopUpItem : public QAbstractButton {

private:

public:
    PopUpItem();
    explicit PopUpItem(QWidget* parent);

private:
    void setupUI();

};