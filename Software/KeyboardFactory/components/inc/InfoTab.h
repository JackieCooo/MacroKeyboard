#pragma once

#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QSizePolicy>
#include <QString>

#include "InfoPanel.h"
#include "GlobalEvent.h"
#include "HIDDevInterface.h"

class InfoTab : public QWidget {

    Q_OBJECT

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

private slots:
    void updateCurDevInfo(HIDDevInterface* newDev);
};
