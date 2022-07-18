#pragma once

#include <QLabel>

#include "HIDDevInterface.h"
#include "InfoPanel.h"

extern HIDDevInterface* curDev;
extern QLabel* moreInfo;
extern InfoPanel* vendorPanel;
extern InfoPanel* productPanel;
extern InfoPanel* versionPanel;

