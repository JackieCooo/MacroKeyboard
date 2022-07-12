#pragma once

#include <QWidget>
#include <QGridLayout>
#include <QListWidget>
#include <QLabel>
#include <QComboBox>
#include <QPushButton>
#include <QHBoxLayout>

class SettingTab : public QWidget {

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

};