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

#include "PopUpItem.h"

class StyleComboBoxPopUp : public QWidget {

    Q_OBJECT

private:
    QVBoxLayout* vLayout = nullptr;
    QScrollArea* scrollArea = nullptr;
    QWidget* viewPort = nullptr;
    QWidget* parent = nullptr;

    QColor bgColor = QColor(60, 60, 60);

public:
    StyleComboBoxPopUp();
    explicit StyleComboBoxPopUp(QWidget* parent);
    [[nodiscard]] QVBoxLayout *getVLayout() const;
    void setVLayout(QVBoxLayout *vLayout);
    [[nodiscard]] QWidget *getParent() const;
    void setParent1(QWidget *parent);

protected:
    void paintEvent(QPaintEvent* e) override;

private:
    void setupUI();

public slots:
    void showPopup();
    void hidePopup();

};