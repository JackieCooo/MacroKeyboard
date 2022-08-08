#include "StyleComboBoxPopUp.h"

StyleComboBoxPopUp::StyleComboBoxPopUp() {
    setupUI();
}

StyleComboBoxPopUp::StyleComboBoxPopUp(QWidget *parent) : QWidget(parent) {
    setupUI();
}

void StyleComboBoxPopUp::setupUI() {
    this->setAttribute(Qt::WA_WindowPropagation);
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::Popup);
    this->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    this->setFixedSize(200, 200);

    scrollArea = new QScrollArea(this);
    scrollArea->setWidgetResizable(true);
    scrollArea->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    scrollArea->setFixedSize(200, 200);
    scrollArea->setFrameStyle(QFrame::NoFrame | QFrame::Plain);
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scrollArea->setWindowFlags(Qt::FramelessWindowHint);
    QPalette palette = scrollArea->palette();
    palette.setBrush(QPalette::Window, Qt::transparent);
    scrollArea->setPalette(palette);

    viewPort = new QWidget(this);
    viewPort->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
    viewPort->setFixedWidth(200);

    scrollArea->setWidget(viewPort);

    vLayout = new QVBoxLayout(viewPort);
    vLayout->setContentsMargins(0, 0, 0, 0);
    vLayout->setSpacing(0);

    viewPort->setLayout(vLayout);
}

QVBoxLayout *StyleComboBoxPopUp::getVLayout() const {
    return vLayout;
}

void StyleComboBoxPopUp::setVLayout(QVBoxLayout *vLayout) {
    this->vLayout = vLayout;
}

void StyleComboBoxPopUp::showPopup() {
    if (this->isVisible()) return;

    this->show();
    this->move(parentWidget->mapToGlobal(parentWidget->rect().bottomLeft()));
}

void StyleComboBoxPopUp::hidePopup() {
    this->hide();
}

void StyleComboBoxPopUp::paintEvent(QPaintEvent *e) {
    QPainter painter(this);
    QBrush brush(Qt::BrushStyle::NoBrush);
    QPen pen(Qt::PenStyle::NoPen);

    brush.setColor(bgColor);
    brush.setStyle(Qt::BrushStyle::SolidPattern);
    painter.setBrush(brush);
    painter.setPen(pen);
    painter.drawRect(rect());
}

QWidget *StyleComboBoxPopUp::getParentWidget() const {
    return this->parentWidget;
}

void StyleComboBoxPopUp::setParentWidget(QWidget *parent) {
    this->parentWidget = parent;
}
