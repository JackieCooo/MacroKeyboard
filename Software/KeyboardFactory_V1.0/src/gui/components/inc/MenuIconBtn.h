#pragma once

#include <QAbstractButton>
#include <QPaintEvent>
#include <QPainter>
#include <QBrush>
#include <QColor>
#include <QImage>
#include <QWidget>
#include <QSizePolicy>

class MenuIconBtn : public QAbstractButton {

private:
    QImage defaultIcon;
    QImage selectedIcon;

public:
    MenuIconBtn();
    explicit MenuIconBtn(QWidget* parent);

protected:
    void paintEvent(QPaintEvent* e) override;

private:
    void setupUI();

};