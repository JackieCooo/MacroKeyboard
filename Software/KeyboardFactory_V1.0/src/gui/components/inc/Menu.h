#pragma once

#include <QWidget>
#include <QVBoxLayout>
#include <QSizePolicy>
#include <QSpacerItem>
#include <QButtonGroup>
#include <QList>

#include "MenuBtn.h"
#include "MenuToolBtn.h"

class Menu : public QWidget {

    Q_OBJECT

private:
    MenuToolBtn* toolBtn = nullptr;
    QButtonGroup* buttonGroup = nullptr;
    QVBoxLayout* vLayout = nullptr;
    QSpacerItem* spacer = nullptr;
    QList<MenuBtn*> menuBtnList;

public:
    Menu();
    explicit Menu(QWidget* parent);

private:
    void setupUI();
    void setupListener();

//private slots:
//    void menuBtnClicked();

signals:
    void menuIndexChanged(int val);

};