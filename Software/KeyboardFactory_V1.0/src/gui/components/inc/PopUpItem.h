#pragma once

#include <QPaintEvent>
#include <QPainter>
#include <QColor>
#include <QBrush>
#include <QPen>
#include <QFont>
#include <QEnterEvent>
#include <QEvent>
#include <QWidget>
#include <QString>
#include <QMouseEvent>

class PopUpItem : public QWidget {

    Q_OBJECT

private:
    QColor hoverColor = QColor(64, 158, 255);
    QColor defaultTextColor = QColor(255, 255, 255);
    QColor hoverTextColor = QColor(70, 70, 70);
    QFont font = QFont("微软雅黑", 12);
    QString text;
    bool hovered = false;

public:
    PopUpItem();
    explicit PopUpItem(QWidget* parent);
    [[nodiscard]] const QString &getText() const;
    void setText(const QString &text);

protected:
    void paintEvent(QPaintEvent* e) override;
    void enterEvent(QEnterEvent* e) override;
    void leaveEvent(QEvent* e) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    void setupUI();

signals:
    void clicked(QWidget* tar);
};