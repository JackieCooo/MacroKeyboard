#pragma once

#include <QWidget>
#include <QGridLayout>
#include <QListWidget>
#include <QLabel>
#include <QComboBox>
#include <QPushButton>
#include <QHBoxLayout>

#include "KeyMapList.h"
#include "IniHandler.h"
#include "VirtualKeyList.h"

class SettingTab : public QWidget {

    Q_OBJECT

private:
    QGridLayout* gLayout = nullptr;
    QHBoxLayout* hLayout = nullptr;
    QWidget* keyDefinePanel = nullptr;
    QListWidget* keyList = nullptr;
    QLabel* label = nullptr;
    QLabel* plusLabel = nullptr;
    QComboBox* firstKey = nullptr;
    QComboBox* secondKey = nullptr;
    QPushButton* okBtn = nullptr;

public:
    SettingTab();
    explicit SettingTab(QWidget* parent);

private:
    void setupUI();

private slots:
    void updateKeyList(KeyMapList* curKeyMap);
    void updateKeySettingPanel(int curRow);
    void setNewKeyMap();

};