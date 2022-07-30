#include "CentralWidget.h"

CentralWidget::CentralWidget() {
    setupUI();
}

CentralWidget::CentralWidget(QWidget* parent) : QWidget(parent) {
    setupUI();
}

void CentralWidget::setupUI() {
    hLayout = new QHBoxLayout(this);
    hLayout->setContentsMargins(0, 0, 0, 0);
    this->setLayout(hLayout);

    menu = new Menu(this);
    hLayout->addWidget(menu);

    styleStackWidget = new StyleStackWidget(this);
    hLayout->addWidget(styleStackWidget);
}

void CentralWidget::paintEvent(QPaintEvent *e) {
    QPainter painter(this);
    QBrush brush(Qt::BrushStyle::SolidPattern);

    painter.setRenderHint(QPainter::Antialiasing);
    brush.setColor(bgColor);
    painter.setBrush(brush);
    painter.drawRect(rect());
}