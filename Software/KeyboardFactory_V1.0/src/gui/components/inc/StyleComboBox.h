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
#include <QMouseEvent>

#include "StyleComboBoxPopUp.h"
#include "PopUpItem.h"

class StyleComboBox : public QWidget {

private:
    StyleComboBoxPopUp* popUp = nullptr;

    QColor borderColor = QColor(200, 200, 200);
    QColor highlightColor = QColor(255, 255, 255);
    QColor indicatorDefaultColor = QColor(255, 255, 255);
    QColor hoverColor = QColor(64, 158, 255);
    QColor textColor = QColor(255, 255, 255);
    QFont font = QFont("微软雅黑", 12);
    QString curText;
    int curIndex = 0;
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
    [[nodiscard]] const QString &getCurText() const;
    void setCurText(const QString &curText);
    [[nodiscard]] int getCurIndex() const;
    void setCurIndex(int curIndex);

protected:
    void paintEvent(QPaintEvent* e) override;
    void enterEvent(QEnterEvent* e) override;
    void leaveEvent(QEvent* e) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    void setupUI();

signals:
    void currentTextChanged(const QString& text);
    void currentIndexChanged(int index);

private slots:
    void onPopUpItemClicked(QWidget* tar);

};