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
    QPen pen(Qt::PenStyle::SolidLine);

    if (isChecked()) {
        painter.setRenderHint(QPainter::Antialiasing);

        brush.setColor(selectedBgColor);
        painter.setBrush(brush);
        painter.drawRect(rect());

        pen.setColor(selectedColor);
        pen.setWidth(2);
        painter.setPen(pen);
        painter.drawLine(5, 5, 5, 10);
        painter.drawLine(5, 5, 10, 5);
        painter.drawLine(5, QWidget::height() - 5, 5, QWidget::height() - 10);
        painter.drawLine(5, QWidget::height() - 5, 10, QWidget::height() - 5);
        painter.drawLine(QWidget::width() - 5, QWidget::height() - 5, QWidget::width() - 5, QWidget::height() - 10);
        painter.drawLine(QWidget::width() - 5, QWidget::height() - 5, QWidget::width() - 10, QWidget::height() - 5);

        painter.drawImage(10, 10, selectedIcon);
    }
    else {
        painter.drawImage(10, 10, defaultIcon);
    }
}

void MenuIconBtn::enterEvent(QEnterEvent *event) {
    hovered = true;
    repaint();
}

void MenuIconBtn::leaveEvent(QEvent *e) {
    hovered = false;
    repaint();
}