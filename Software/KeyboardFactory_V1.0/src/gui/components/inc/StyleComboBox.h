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
#include "PopUpModel.h"

class StyleComboBox : public QWidget {

    Q_OBJECT

private:
    StyleComboBoxPopUp* popUp = nullptr;
    PopUpModel* popUpModel = nullptr;

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
    void addItem(const QString& text, const QVariant& userData = QVariant());
    [[nodiscard]] const QString &getCurText() const;
    void setCurText(const QString &curText);
    [[nodiscard]] int getCurIndex() const;
    void setCurIndex(int curIndex);
    [[nodiscard]] PopUpModel *getPopUpModel() const;
    void setPopUpModel(PopUpModel *popUpModel);

protected:
    void paintEvent(QPaintEvent* e) override;
    void enterEvent(QEnterEvent* e) override;
    void leaveEvent(QEvent* e) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    void setupUI();
    void setupListener();

signals:
    void currentTextChanged(const QString& text);
    void currentIndexChanged(int index);

private slots:
    void onPopUpItemClicked(QWidget* tar);
    void updateCurrentItem();
    void updateCurrentItem(const QString& text, int index);

};