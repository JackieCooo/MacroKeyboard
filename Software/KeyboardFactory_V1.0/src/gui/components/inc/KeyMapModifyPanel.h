#pragma once

#include <QWidget>
#include <QHBoxLayout>
#include <QLabel>
#include <QSpacerItem>

#include "StyleComboBox.h"

class KeyMapModifyPanel : public QWidget {

private:
    QVBoxLayout* vLayout = nullptr;
    QLabel* label = nullptr;
    StyleComboBox* comboBox = nullptr;
    QSpacerItem* spacer = nullptr;

public:
    KeyMapModifyPanel();
    explicit KeyMapModifyPanel(QWidget* parent);

private:
    void setupUI();

};