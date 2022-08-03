#include "StyleComboBox.h"

StyleComboBox::StyleComboBox() {
    setupUI();
}

StyleComboBox::StyleComboBox(QWidget *parent) : QWidget(parent) {
    setupUI();
}

void StyleComboBox::setupUI() {
    this->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    this->setFixedSize(200, 35);

    popUp = new StyleComboBoxPopUp(this);
}

void StyleComboBox::paintEvent(QPaintEvent *e) {
    QPainter painter(this);
    QBrush brush(Qt::BrushStyle::NoBrush);
    QPen pen(Qt::PenStyle::NoPen);

    // 绘制边框
    painter.setRenderHint(QPainter::Antialiasing);
    pen.setStyle(Qt::PenStyle::SolidLine);
    if (hovered) pen.setColor(hoverColor);
    else pen.setColor(borderColor);
    pen.setWidth(1);
    painter.setPen(pen);
    painter.drawRect(rect());

    // 绘制边框高光
    if (hovered) pen.setColor(hoverColor);
    else pen.setColor(highlightColor);
    painter.setPen(pen);
    painter.drawLine(0, 0, highlightLength, 0);
    painter.drawLine(0, 0, 0, highlightLength);
    painter.drawLine(0, QWidget::height(), 0, QWidget::height() - highlightLength);
    painter.drawLine(0, QWidget::height(), highlightLength, QWidget::height());
    painter.drawLine(QWidget::width(), QWidget::height(), QWidget::width() - highlightLength, QWidget::height());
    painter.drawLine(QWidget::width(), QWidget::height(), QWidget::width(), QWidget::height() - highlightLength);

    // 绘制指示器
    pen.setStyle(Qt::PenStyle::NoPen);
    painter.setPen(pen);
    brush.setStyle(Qt::BrushStyle::SolidPattern);
    if (hovered) brush.setColor(hoverColor);
    else brush.setColor(indicatorDefaultColor);
    painter.setBrush(brush);
    double scale = 10.0;  // 三角形放大系数
    double offsetX = QWidget::width() - 15.0 - scale;  // 三角形X轴偏移
    double offsetY = (QWidget::height() - scale * indicatorBasePoints[2].y()) / 2.0;  // 三角形Y轴偏移
    QPointF indicatorPoints[3] = {};
    for (int i = 0; i < 3; ++i) {
        indicatorPoints[i] = QPointF(indicatorBasePoints[i].x() * scale + offsetX, indicatorBasePoints[i].y() * scale + offsetY);
    }
    painter.drawPolygon(indicatorPoints, 3);

    // 绘制文本
    pen.setStyle(Qt::PenStyle::SolidLine);
    pen.setColor(textColor);
    painter.setPen(pen);
    brush.setStyle(Qt::BrushStyle::NoBrush);
    painter.setBrush(brush);
    painter.setFont(font);
    painter.drawText(8, 0, 150, QWidget::height(), Qt::AlignLeft | Qt::AlignVCenter, currentText());
}

void StyleComboBox::enterEvent(QEnterEvent *e) {
    hovered = true;
    repaint();
}

void StyleComboBox::leaveEvent(QEvent *e) {
    hovered = false;
    repaint();
}
