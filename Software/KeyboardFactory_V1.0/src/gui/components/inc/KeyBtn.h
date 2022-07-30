#pragma once

#include <QAbstractButton>
#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include <QBrush>
#include <QPaintEvent>
#include <QColor>
#include <QPen>

class KeyBtn : public QAbstractButton {

private:
    QColor defaultColor = QColor(40, 40, 40);
    QColor highlightColor = QColor(70, 70, 70);
    int row = -1;
    int col = -1;

public:
    KeyBtn();
    explicit KeyBtn(QWidget* parent);
    [[nodiscard]] int getRow() const;
    void setRow(int row);
    [[nodiscard]] int getCol() const;
    void setCol(int col);

protected:
    void paintEvent(QPaintEvent* e) override;

private:
    void setupUI();

};