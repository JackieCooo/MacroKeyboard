#pragma once

#include <QAbstractButton>
#include <QColor>
#include <QPainter>
#include <QImage>
#include <QPaintEvent>
#include <QEnterEvent>
#include <QEvent>
#include <QWidget>
#include <QString>
#include <QSizePolicy>
#include <QEnterEvent>
#include <QEvent>

class MenuToolBtn : public QAbstractButton {

private:
    QImage defaultIcon;
    QImage hoverIcon;
    bool hovered = false;

public:
    MenuToolBtn();
    explicit MenuToolBtn(QWidget* parent);
    MenuToolBtn(QWidget* parent, const QString& defaultIconPath, const QString& hoverIconPath);

protected:
    void paintEvent(QPaintEvent* e) override;
    void enterEvent(QEnterEvent* e) override;
    void leaveEvent(QEvent* e) override;

private:
    void setupUI();

};