#include "SidePanel.h"

SidePanel::SidePanel() {
    setupUI();
}

SidePanel::SidePanel(QWidget* parent) : QWidget(parent) {
    setupUI();
}

void SidePanel::setupUI() {
    vLayout = new QVBoxLayout(this);
    this->setLayout(vLayout);

    keyboardBtn = new MenuIconBtn(this);
    keyboardBtn->setChecked(true);
    vLayout->addWidget(keyboardBtn);

    settingBtn = new MenuIconBtn(this);
    vLayout->addWidget(settingBtn);

    spacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
    vLayout->addItem(spacer);

    buttonGroup = new QButtonGroup();
    buttonGroup->setExclusive(true);
    buttonGroup->addButton(keyboardBtn);
    buttonGroup->addButton(settingBtn);
}

void SidePanel::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    QPen pen(Qt::PenStyle::SolidLine);

    painter.setRenderHint(QPainter::Antialiasing);
    pen.setColor(borderColor);
    pen.setWidth(1);
    painter.setPen(pen);
    painter.drawLine(QWidget::width() - 1, 0, QWidget::width() - 1, QWidget::height());
}
