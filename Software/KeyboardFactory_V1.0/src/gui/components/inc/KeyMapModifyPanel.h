#pragma once

#include <QWidget>
#include <QHBoxLayout>
#include <QLabel>

class KeyMapModifyPanel : public QWidget {

private:
    QVBoxLayout* vLayout = nullptr;
    QLabel* label = nullptr;

public:
    KeyMapModifyPanel();
    explicit KeyMapModifyPanel(QWidget* parent);

private:
    void setupUI();

};