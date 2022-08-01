#pragma once

#include <QWidget>
#include <QHBoxLayout>
#include <QChar>
#include <QString>

#include "KeyboardLayout.h"
#include "KeyBtn.h"
#include "KeyMapModifyPanel.h"

class KeyboardModifyPanel : public QWidget {

private:
    KeyboardLayout* keyboardLayout = nullptr;
    QHBoxLayout* hLayout = nullptr;
    KeyMapModifyPanel* keyMapModifyPanel = nullptr;

public:
    KeyboardModifyPanel();
    explicit KeyboardModifyPanel(QWidget* parent);

private:
    void setupUI();

};