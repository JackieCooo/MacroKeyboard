#pragma once

#include <QAbstractButton>
#include <QSizePolicy>
#include <QPainter>
#include <QPaintEvent>
#include <QColor>
#include <QBrush>
#include <QPen>
#include <QEnterEvent>
#include <QEvent>
#include <QImage>
#include <QWidget>
#include <QHBoxLayout>
#include <QObject>
#include <QFont>

class MenuBtn : public QAbstractButton {

    Q_OBJECT

private:
    const int iconWidth = 50;
    const int textWidth = 80;
    bool hovered = false;
    bool expanded = false;
    QImage defaultIcon;
    QImage selectedIcon;
    QColor selectedBgColor = QColor(255, 255, 255);
    QColor selectedColor = QColor(125, 125, 125);
    QColor hoverColor = QColor(75, 75, 75);
    QColor textColor = QColor(255, 255, 255);
    QFont font = QFont("微软雅黑", 10);

public:
    MenuBtn();
    explicit MenuBtn(QWidget* parent);
    MenuBtn(QWidget* parent, const QString& defaultIconPath, const QString& selectedIconPath, const QString& text);

protected:
    void paintEvent(QPaintEvent* e) override;
    void enterEvent(QEnterEvent* e) override;
    void leaveEvent(QEvent* e) override;

private:
    void setupUI();

public slots:
    void stateChange();

};