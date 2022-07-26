#pragma once

#include <QAbstractButton>
#include <QPaintEvent>
#include <QString>
#include <QPainter>
#include <QBrush>
#include <QColor>
#include <QPen>
#include <QFont>
#include <QSizePolicy>
#include <QEnterEvent>
#include <QEvent>
#include <QCursor>

class MenuBtn : public QAbstractButton {

private:
    uint8_t roundRadius = 8;
    QColor bgColor = QColor(66, 66, 66);
    QColor textColor = QColor(255, 255, 255);
    QFont font = QFont("微软雅黑", 12);
    bool hovered = false;

public:
    MenuBtn();
    explicit MenuBtn(QWidget* parent);
    MenuBtn(const QString& text, QWidget* parent);

protected:
    void paintEvent(QPaintEvent* e) override;
    void enterEvent(QEnterEvent* e) override;
    void leaveEvent(QEvent* e) override;

private:
    void setupUI(const QString& text = nullptr);

};