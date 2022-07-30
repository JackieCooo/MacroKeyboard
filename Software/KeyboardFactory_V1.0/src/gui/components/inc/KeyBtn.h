#pragma once

#include <QAbstractButton>
#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include <QBrush>
#include <QPaintEvent>
#include <QColor>
#include <QPen>
#include <QEnterEvent>
#include <QEvent>
#include <QPropertyAnimation>
#include <QEasingCurve>
#include <QPoint>
#include <QFont>

class KeyBtn : public QAbstractButton {

private:
    QColor defaultColor = QColor(40, 40, 40);
    QColor highlightColor = QColor(70, 70, 70);
    QColor textColor = QColor(255, 255, 255);
    QFont font = QFont("ROG Fonts", 16);
    int row = -1;
    int col = -1;
    const int borderRadius = 3;
    const int btnSize = 60;

public:
    KeyBtn();
    explicit KeyBtn(QWidget* parent);
    KeyBtn(QWidget* parent, const QString& text);
    [[nodiscard]] int getRow() const;
    void setRow(int row);
    [[nodiscard]] int getCol() const;
    void setCol(int col);

protected:
    void paintEvent(QPaintEvent* e) override;
    void enterEvent(QEnterEvent* e) override;
    void leaveEvent(QEvent* e) override;

private:
    void setupUI();

};