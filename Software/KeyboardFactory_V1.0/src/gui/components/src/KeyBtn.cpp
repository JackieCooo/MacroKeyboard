#include "KeyBtn.h"

KeyBtn::KeyBtn() {
    setupUI();
}

KeyBtn::KeyBtn(QWidget *parent) : QAbstractButton(parent) {
    setupUI();
}

void KeyBtn::setupUI() {
    this->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    this->setFixedSize(60, 60);
    this->setCheckable(false);
}

void KeyBtn::paintEvent(QPaintEvent *e) {
    QPainter painter(this);
    QBrush brush(Qt::BrushStyle::SolidPattern);
    QPen pen(Qt::PenStyle::NoPen);

    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(pen);

    brush.setColor(defaultColor);
    painter.setBrush(brush);
    painter.drawRoundedRect(rect(), 3, 3);
    brush.setColor(highlightColor);
    painter.setBrush(brush);
    painter.drawRoundedRect(8, 3, QWidget::width() - 16, QWidget::height() - 17, 3, 3);
}

int KeyBtn::getRow() const {
    return row;
}

void KeyBtn::setRow(int row) {
    KeyBtn::row = row;
}

int KeyBtn::getCol() const {
    return col;
}

void KeyBtn::setCol(int col) {
    KeyBtn::col = col;
}
