#pragma once

#include <QComboBox>
#include <QSizePolicy>
#include <QPaintEvent>
#include <QPainter>
#include <QColor>
#include <QBrush>
#include <QPen>
#include <QFont>
#include <QPointF>

class StyleComboBox : public QComboBox {

private:
    QColor borderColor = QColor(200, 200, 200);
    QColor highlightColor = QColor(255, 255, 255);
    QColor indicatorDefaultColor = QColor(255, 255, 255);
    QColor indicatorHoverColor = QColor(64, 158, 255);
    int highlightLength = 8;
    const QPointF indicatorBasePoints[3] = {
        QPointF(0.00, 0.87),
        QPointF(1.00, 0.87),
        QPointF(0.50, 0.00)
    };

public:
    StyleComboBox();
    explicit StyleComboBox(QWidget* parent);

protected:
    void paintEvent(QPaintEvent* e) override;

private:
    void setupUI();

};