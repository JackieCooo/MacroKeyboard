#include "StyleComboBox.h"

StyleComboBox::StyleComboBox() {
    setupUI();
}

StyleComboBox::StyleComboBox(QWidget *parent) : QComboBox(parent) {
    setupUI();
}

void StyleComboBox::setupUI() {
    this->setEditable(false);
    this->setFrame(false);
    this->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    this->setFixedSize(200, 35);
}

void StyleComboBox::paintEvent(QPaintEvent *e) {
    QPainter painter(this);
    QBrush brush(Qt::BrushStyle::NoBrush);
    QPen pen(Qt::PenStyle::NoPen);

    painter.setRenderHint(QPainter::Antialiasing);
    pen.setStyle(Qt::PenStyle::SolidLine);
    pen.setColor(borderColor);
    pen.setWidth(1);
    painter.setPen(pen);
    painter.drawRect(rect());

    pen.setColor(highlightColor);
    painter.setPen(pen);
    painter.drawLine(0, 0, highlightLength, 0);
    painter.drawLine(0, 0, 0, highlightLength);
    painter.drawLine(0, QWidget::height(), 0, QWidget::height() - highlightLength);
    painter.drawLine(0, QWidget::height(), highlightLength, QWidget::height());
    painter.drawLine(QWidget::width(), QWidget::height(), QWidget::width() - highlightLength, QWidget::height());
    painter.drawLine(QWidget::width(), QWidget::height(), QWidget::width(), QWidget::height() - highlightLength);

    pen.setStyle(Qt::PenStyle::NoPen);
    painter.setPen(pen);
    brush.setStyle(Qt::BrushStyle::SolidPattern);
    brush.setColor(indicatorDefaultColor);
    painter.setBrush(brush);
    int indicatorSize = 10;  // 三角形边长
    int marginRight = 5;  // 指示器右缩进
    QPointF indicatorPoints[3] = {  // 3个点在组件中的坐标
        QPointF(QWidget::width() - marginRight - indicatorBasePoints[0].x() * indicatorSize, indicatorBasePoints[0].y() * indicatorSize),
        QPointF(QWidget::width() - marginRight, indicatorBasePoints[1].y() * indicatorSize),
        QPointF(QWidget::width() - marginRight - indicatorBasePoints[2].x() * indicatorSize / 2.0, 0)
    };
    painter.drawPolygon(indicatorBasePoints, 3);
}
