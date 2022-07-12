#pragma once

#include <QWidget>
#include <QLabel>
#include <QComboBox>
#include <QHBoxLayout>
#include <QSizePolicy>

class TopPanel : public QWidget {

private:
    QHBoxLayout* hLayout = nullptr;
    QLabel* label = nullptr;
    QComboBox* deviceList = nullptr;

public:
    TopPanel();
    explicit TopPanel(QWidget* parent);

private:
    void setupUI();

};