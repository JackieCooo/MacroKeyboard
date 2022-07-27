#include "MenuTextBtn.h"

MenuTextBtn::MenuTextBtn() {
    setupUI();
}

MenuTextBtn::MenuTextBtn(QWidget *parent) : QAbstractButton(parent) {
    setupUI();
}

MenuTextBtn::MenuTextBtn(const QString& text, QWidget *parent) : QAbstractButton(parent) {
    setupUI(text);
}

void MenuTextBtn::setupUI(const QString& text) {
    this->setText(text);
    this->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    this->setFixedSize(100, 40);
    this->setCheckable(true);
    this->setChecked(false);
    this->setMouseTracking(true);
    this->setObjectName("MenuTextBtn");
}

void MenuTextBtn::paintEvent(QPaintEvent *e) {
    QPainter painter(this);
    QBrush brush(Qt::BrushStyle::SolidPattern);
    QPen pen(Qt::PenStyle::SolidLine);

    if (this->isChecked() || this->hovered) {
        brush.setColor(bgColor);
        painter.setBrush(brush);
        painter.setRenderHint(QPainter::Antialiasing, true);
        painter.drawRoundedRect(0, 0, QWidget::width(), QWidget::height(), roundRadius, roundRadius);
    }

    pen.setColor(textColor);
    pen.setJoinStyle(Qt::PenJoinStyle::RoundJoin);
    painter.setPen(pen);
    painter.setFont(font);
    painter.drawText(0, 0, QWidget::width(), QWidget::height(), Qt::AlignCenter, this->text());
}

void MenuTextBtn::enterEvent(QEnterEvent *e) {
    hovered = true;
    this->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
    repaint();
}

void MenuTextBtn::leaveEvent(QEvent *event) {
    hovered = false;
    this->setCursor(QCursor(Qt::CursorShape::ArrowCursor));
    repaint();
}