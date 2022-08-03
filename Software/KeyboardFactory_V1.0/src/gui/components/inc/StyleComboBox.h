#pragma once

#include <QWidget>
#include <QSizePolicy>
#include <QPaintEvent>
#include <QPainter>
#include <QColor>
#include <QBrush>
#include <QPen>
#include <QFont>
#include <QPointF>
#include <QEnterEvent>
#include <QEvent>
#include <QString>

#include "StyleComboBoxPopUp.h"

class StyleComboBox : public QWidget {

private:
    StyleComboBoxPopUp* popUp = nullptr;

    QColor borderColor = QColor(200, 200, 200);
    QColor highlightColor = QColor(255, 255, 255);
    QColor indicatorDefaultColor = QColor(255, 255, 255);
    QColor hoverColor = QColor(64, 158, 255);
    QColor textColor = QColor(255, 255, 255);
    QFont font = QFont("微软雅黑", 12);
    bool hovered = false;
    const int highlightLength = 8;
    const QPointF indicatorBasePoints[3] = {
        QPointF(0.00, 0.00),
        QPointF(1.00, 0.00),
        QPointF(0.50, 0.87)
    };

public:
    StyleComboBox();
    explicit StyleComboBox(QWidget* parent);
    void addItem(const QString& text);

protected:
    void paintEvent(QPaintEvent* e) override;
    void enterEvent(QEnterEvent* e) override;
    void leaveEvent(QEvent* e) override;

private:
    void setupUI();

};