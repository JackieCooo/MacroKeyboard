#pragma once

#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QSizePolicy>

#include "InfoPanel.h"

class InfoTab : public QWidget {

private:
    QGridLayout* gLayout = nullptr;
    QLabel* moreInfo = nullptr;
    InfoPanel* vendorPanel = nullptr;
    InfoPanel* productPanel = nullptr;
    InfoPanel* versionPanel = nullptr;

public:
    InfoTab();
    explicit InfoTab(QWidget* parent);

private:
    void setupUI();

};
