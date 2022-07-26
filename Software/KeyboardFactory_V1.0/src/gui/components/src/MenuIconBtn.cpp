#include "MenuIconBtn.h"

MenuIconBtn::MenuIconBtn() {
    setupUI();
}

MenuIconBtn::MenuIconBtn(QWidget* parent) : QAbstractButton(parent) {
    setupUI();
}

void MenuIconBtn::setupUI() {
    this->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    this->setFixedSize(50, 50);
    this->setCheckable(true);
    this->setChecked(false);
}

void MenuIconBtn::paintEvent(QPaintEvent *e) {
    QPainter painter(this);
    QBrush brush(Qt::BrushStyle::SolidPattern);

    if (isChecked()) {

    }
    else {

    }
}