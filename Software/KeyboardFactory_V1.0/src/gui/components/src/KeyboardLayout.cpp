#include "KeyboardLayout.h"

KeyboardLayout::KeyboardLayout() {
    setupUI();
}

KeyboardLayout::~KeyboardLayout() {
    for (auto i : keyList) {
        delete i;
    }
}

KeyboardLayout::KeyboardLayout(QWidget *parent) : QWidget(parent) {
    setupUI();
}

KeyboardLayout::KeyboardLayout(QWidget *parent, int width, int height) : QWidget(parent) {
    this->setFixedSize(width, height);
    setupUI();
}

void KeyboardLayout::setupUI() {
    this->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    gLayout = new QGridLayout(this);
    gLayout->setContentsMargins(10, 10, 10, 10);
    this->setLayout(gLayout);
}

void KeyboardLayout::paintEvent(QPaintEvent *e) {
    QPainter painter(this);
    QPen pen(Qt::PenStyle::SolidLine);

    painter.setRenderHint(QPainter::Antialiasing);

    pen.setColor(borderColor);
    pen.setWidth(borderWidth);
    painter.setPen(pen);
    painter.drawRoundedRect(borderWidth, borderWidth, QWidget::width() - borderWidth - 1, QWidget::height() - borderWidth - 1, 5, 5);
}

const QList<KeyBtn *> &KeyboardLayout::getKeyList() const {
    return keyList;
}

void KeyboardLayout::setKeyList(const QList<KeyBtn *> &keyList) {
    this->keyList = keyList;
}

void KeyboardLayout::addKeyBtn(KeyBtn &key, int row, int col) {
    key.setRow(row);
    key.setCol(col);
    keyList.push_back(&key);

    gLayout->addWidget(&key, row, col);
}

void KeyboardLayout::addKeyBtns() {
}

void KeyboardLayout::setLayoutMargin(int left, int top, int right, int bottom) {
    if (this->gLayout != nullptr) this->gLayout->setContentsMargins(left, top, right, bottom);
}
