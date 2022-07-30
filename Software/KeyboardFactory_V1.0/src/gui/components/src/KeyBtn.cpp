#include "KeyBtn.h"

KeyBtn::KeyBtn() {
    setupUI();
}

KeyBtn::KeyBtn(QWidget *parent) : QAbstractButton(parent) {
    setupUI();
}

KeyBtn::KeyBtn(QWidget *parent, const QString &text) : QAbstractButton(parent) {
    this->setText(text);
    setupUI();
}

void KeyBtn::setupUI() {
    this->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    this->setFixedSize(btnSize, btnSize);
    this->setCheckable(false);
}

void KeyBtn::paintEvent(QPaintEvent *e) {
    QPainter painter(this);
    QBrush brush(Qt::BrushStyle::SolidPattern);
    QPen pen(Qt::PenStyle::NoPen);

    painter.setRenderHint(QPainter::Antialiasing);
    painter.setRenderHint(QPainter::TextAntialiasing);
    painter.setPen(pen);

    brush.setColor(defaultColor);
    painter.setBrush(brush);
    painter.drawRoundedRect(rect(), borderRadius, borderRadius);
    brush.setColor(highlightColor);
    painter.setBrush(brush);
    painter.drawRoundedRect(8, 3, btnSize - 16, btnSize - 17, borderRadius, borderRadius);

    pen = QPen(Qt::PenStyle::SolidLine);
    pen.setColor(textColor);
    painter.setPen(pen);
    painter.setFont(font);
    painter.drawText(rect(), Qt::AlignCenter, text());
}

void KeyBtn::enterEvent(QEnterEvent *e) {
    this->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
    QPropertyAnimation* animation = new QPropertyAnimation(this, "pos");
    animation->setDuration(500);
    animation->setStartValue(QPoint(this->x(), this->y()));
    animation->setEndValue(QPoint(this->x(), this->y() - 5));
    animation->setEasingCurve(QEasingCurve::InOutQuart);
    animation->start(QAbstractAnimation::DeleteWhenStopped);
}

void KeyBtn::leaveEvent(QEvent *e) {
    this->setCursor(QCursor(Qt::CursorShape::ArrowCursor));
    QPropertyAnimation* animation = new QPropertyAnimation(this, "pos");
    animation->setDuration(500);
    animation->setStartValue(QPoint(this->x(), this->y()));
    animation->setEndValue(QPoint(this->x(), this->y() + 5));
    animation->setEasingCurve(QEasingCurve::InOutQuart);
    animation->start(QAbstractAnimation::DeleteWhenStopped);
}

int KeyBtn::getRow() const {
    return row;
}

void KeyBtn::setRow(int row) {
    this->row = row;
}

int KeyBtn::getCol() const {
    return col;
}

void KeyBtn::setCol(int col) {
    this->col = col;
}
