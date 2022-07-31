#include "MenuBtn.h"

MenuBtn::MenuBtn() {
    setupUI();
}

MenuBtn::MenuBtn(QWidget* parent) : QAbstractButton(parent) {
    setupUI();
}

MenuBtn::MenuBtn(QWidget *parent, const QString &defaultIconPath, const QString &selectedIconPath, const QString& text) : QAbstractButton(parent) {
    this->defaultIcon = QImage(defaultIconPath);
    this->selectedIcon = QImage(selectedIconPath);
    this->setText(text);
    setupUI();
}

void MenuBtn::setupUI() {
    this->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    this->setFixedSize(50, 50);
    this->setCheckable(true);
    this->setChecked(false);
}

void MenuBtn::paintEvent(QPaintEvent *e) {
    QPainter painter(this);
    QBrush brush(Qt::BrushStyle::SolidPattern);
    QPen pen(Qt::PenStyle::SolidLine);

    painter.setRenderHint(QPainter::Antialiasing);
    painter.setRenderHint(QPainter::LosslessImageRendering);

    if (isChecked()) {
        brush.setColor(selectedBgColor);
        painter.setBrush(brush);
        painter.drawRect(0, 0, iconWidth, QWidget::height());

        if (hovered && expanded) {
            brush.setColor(hoverColor);
            painter.setBrush(brush);
            painter.drawRect(iconWidth, 0, textWidth, QWidget::height());
        }

        pen.setColor(selectedColor);
        pen.setWidth(2);
        painter.setPen(pen);
        painter.drawLine(5, 5, 5, 10);
        painter.drawLine(5, 5, 10, 5);
        painter.drawLine(5, QWidget::height() - 5, 5, QWidget::height() - 10);
        painter.drawLine(5, QWidget::height() - 5, 10, QWidget::height() - 5);
        painter.drawLine(iconWidth - 5, QWidget::height() - 5, iconWidth - 5, QWidget::height() - 10);
        painter.drawLine(iconWidth - 5, QWidget::height() - 5, iconWidth - 10, QWidget::height() - 5);

        painter.drawImage(10, 10, selectedIcon);
    }
    else {
        if (hovered) {
            brush.setColor(hoverColor);
            painter.setBrush(brush);
            painter.drawRect(rect());
        }

        painter.drawImage(10, 10, defaultIcon);
    }

    if (expanded) {
        painter.setFont(font);
        pen.setColor(textColor);
        painter.setPen(pen);
        painter.drawText(iconWidth + 5, 0, textWidth, QWidget::height(), Qt::AlignVCenter | Qt::AlignLeft, text());
    }
}

void MenuBtn::enterEvent(QEnterEvent *e) {
    hovered = true;
    this->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
    repaint();
}

void MenuBtn::leaveEvent(QEvent *e) {
    hovered = false;
    this->setCursor(QCursor(Qt::CursorShape::ArrowCursor));
    repaint();
}

void MenuBtn::stateChange() {
    expanded = !expanded;
    if (expanded) {
        this->setFixedSize(QWidget::width() + textWidth, QWidget::height());
    }
    else {
        this->setFixedSize(QWidget::width() - textWidth, QWidget::height());
    }
    repaint();
}