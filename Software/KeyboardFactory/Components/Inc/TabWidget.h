#pragma once

#include <QTabWidget>
#include <QWidget>

class TabWidget : public QTabWidget {

private:

public:
    TabWidget();
    TabWidget(QWidget* parent);
    void setupUI();
};

