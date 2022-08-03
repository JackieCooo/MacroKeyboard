#include "StyleComboBoxPopUp.h"

StyleComboBoxPopUp::StyleComboBoxPopUp() {
    setupUI();
}

StyleComboBoxPopUp::StyleComboBoxPopUp(QWidget *parent) : QWidget(parent) {
    setupUI();
}

void StyleComboBoxPopUp::setupUI() {
    this->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
    this->setFixedWidth(200);
}

