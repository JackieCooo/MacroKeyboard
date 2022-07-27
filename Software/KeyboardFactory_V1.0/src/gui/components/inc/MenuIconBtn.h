#pragma once

#include <QAbstractButton>
#include <QPaintEvent>
#include <QPainter>
#include <QBrush>
#include <QColor>
#include <QImage>
#include <QWidget>
#include <QSizePolicy>
#include <QPen>
#include <QEnterEvent>
#include <QEvent>
#include <QRect>

class MenuIconBtn : public QAbstractButton {

private:
    QImage defaultIcon = QImage("../src/gui/icons/Keyboard_Default_30px.png");
    QImage selectedIcon = QImage("../src/gui/icons/Keyboard_Selected_30px.png");

    QColor selectedBgColor = QColor(255, 255, 255);
    QColor selectedColor = QColor(125, 125, 125);
    bool hovered = false;

public:
    MenuIconBtn();
    explicit MenuIconBtn(QWidget* parent);

protected:
    void paintEvent(QPaintEvent* e) override;
    void enterEvent(QEnterEvent* e) override;
    void leaveEvent(QEvent* e) override;

private:
    void setupUI();

};