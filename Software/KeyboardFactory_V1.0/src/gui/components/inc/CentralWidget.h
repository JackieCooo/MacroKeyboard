#pragma once

#include <QWidget>
#include <QHBoxLayout>
#include <QPaintEvent>
#include <QPainter>
#include <QBrush>
#include <QColor>

#include "StyleStackWidget.h"
#include "Menu.h"

class CentralWidget : public QWidget {

private:
    Menu* menu = nullptr;
    StyleStackWidget* styleStackWidget = nullptr;
    QHBoxLayout* hLayout = nullptr;

    QColor bgColor = QColor(20, 20, 20);

protected:
    void paintEvent(QPaintEvent* e) override;

public:
    CentralWidget();
    explicit CentralWidget(QWidget* parent);

private:
    void setupUI();

};