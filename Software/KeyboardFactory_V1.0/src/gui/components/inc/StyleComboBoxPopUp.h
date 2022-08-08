#pragma once

#include <QWidget>
#include <QObject>
#include <QVBoxLayout>
#include <QPaintEvent>
#include <QPainter>
#include <QColor>
#include <QBrush>
#include <QPen>
#include <QScrollArea>
#include <QPalette>

#include "PopUpItem.h"

class StyleComboBoxPopUp : public QWidget {

    Q_OBJECT

private:
    QVBoxLayout* vLayout = nullptr;
    QScrollArea* scrollArea = nullptr;
    QWidget* viewPort = nullptr;
    QWidget* parentWidget = nullptr;

    QColor bgColor = QColor(70, 70, 70);

public:
    StyleComboBoxPopUp();
    explicit StyleComboBoxPopUp(QWidget* parent);
    [[nodiscard]] QVBoxLayout *getVLayout() const;
    void setVLayout(QVBoxLayout *vLayout);
    [[nodiscard]] QWidget *getParentWidget() const;
    void setParentWidget(QWidget *parent);

protected:
    void paintEvent(QPaintEvent* e) override;

private:
    void setupUI();

public slots:
    void showPopup();
    void hidePopup();

};