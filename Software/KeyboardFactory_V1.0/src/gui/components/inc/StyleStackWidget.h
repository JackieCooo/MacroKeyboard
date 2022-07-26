#pragma once

#include <QStackedWidget>
#include <QWidget>

class StyleStackWidget : public QStackedWidget {

private:

public:
    StyleStackWidget();
    explicit StyleStackWidget(QWidget* parent);

private:
    void setupUI();

};