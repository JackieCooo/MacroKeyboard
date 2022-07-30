#include "MenuToolBtn.h"

MenuToolBtn::MenuToolBtn() {
    setupUI();
}

MenuToolBtn::MenuToolBtn(QWidget *parent) : QAbstractButton(parent) {
    setupUI();
}

MenuToolBtn::MenuToolBtn(QWidget *parent, const QString &defaultIconPath, const QString &hoverIconPath) : QAbstractButton(parent) {
    defaultIcon = QImage(defaultIconPath);
    hoverIcon = QImage(hoverIconPath);
    setupUI();
}

void MenuToolBtn::setupUI() {
    this->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    this->setFixedSize(50, 50);
}

void MenuToolBtn::paintEvent(QPaintEvent *e) {
    QPainter painter(this);

    painter.setRenderHint(QPainter::Antialiasing);

    if (hovered) {
        painter.drawImage(10, 10, hoverIcon);
    }
    else {
        painter.drawImage(10, 10, defaultIcon);
    }
}

void MenuToolBtn::enterEvent(QEnterEvent *e) {
    hovered = true;
    this->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
    repaint();
}

void MenuToolBtn::leaveEvent(QEvent *e) {
    hovered = false;
    this->setCursor(QCursor(Qt::CursorShape::ArrowCursor));
    repaint();
}
