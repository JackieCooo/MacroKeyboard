#pragma once

#include <QComboBox>

class StyleComboBox : public QComboBox {

private:

public:
    StyleComboBox();
    explicit StyleComboBox(QWidget* parent);

private:
    void setupUI();

};