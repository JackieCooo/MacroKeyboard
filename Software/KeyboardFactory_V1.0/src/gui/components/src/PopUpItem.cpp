#include "PopUpItem.h"

PopUpItem::PopUpItem() {
    setupUI();
}

PopUpItem::PopUpItem(QWidget *parent) : QWidget(parent) {
    setupUI();
}

void PopUpItem::setupUI() {
    this->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    this->setFixedSize(200, 30);
}

void PopUpItem::paintEvent(QPaintEvent *e) {
    QPainter painter(this);
    QBrush brush(Qt::BrushStyle::NoBrush);
    QPen pen(Qt::PenStyle::NoPen);

    painter.setRenderHint(QPainter::Antialiasing);
    painter.setRenderHint(QPainter::TextAntialiasing);

    // 绘制悬停样式
    if (hovered) {
        brush.setStyle(Qt::BrushStyle::SolidPattern);
        brush.setColor(hoverColor);
        painter.setBrush(brush);
        painter.setPen(pen);
        painter.drawRect(rect());
    }

    // 绘制文字
    painter.setFont(font);
    if (hovered) {
        pen.setColor(hoverTextColor);
    }
    else {
        pen.setColor(defaultTextColor);
    }
    pen.setStyle(Qt::SolidLine);
    painter.setPen(pen);
    painter.drawText(5, 0, QWidget::width() - 5, QWidget::height(), Qt::AlignLeft | Qt::AlignVCenter, text);
}

void PopUpItem::enterEvent(QEnterEvent *e) {
    hovered = true;
    repaint();
}

void PopUpItem::leaveEvent(QEvent *e) {
    hovered = false;
    repaint();
}

void PopUpItem::mouseReleaseEvent(QMouseEvent *event) {
    emit clicked(this);
}

const QString &PopUpItem::getText() const {
    return text;
}

void PopUpItem::setText(const QString &text) {
    this->text = text;
}
