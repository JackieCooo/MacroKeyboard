#pragma once

#include <QWidget>
#include <QVBoxLayout>
#include <QSpacerItem>
#include <QButtonGroup>
#include <QSizePolicy>
#include <QPaintEvent>
#include <QPainter>
#include <QBrush>
#include <QColor>
#include <QPen>

#include "MenuTextBtn.h"
#include "MenuIconBtn.h"

class SidePanel : public QWidget {

private:
    QVBoxLayout* vLayout = nullptr;
    MenuIconBtn* keyboardBtn = nullptr;
    MenuIconBtn* settingBtn = nullptr;
    QButtonGroup* buttonGroup = nullptr;
    QSpacerItem* spacer = nullptr;

    QColor borderColor = QColor(66, 66, 66);

public:
    SidePanel();
    explicit SidePanel(QWidget* parent);

protected:
    void paintEvent(QPaintEvent* e) override;

private:
    void setupUI();

};