#pragma once

#include <QWidget>
#include <QSizePolicy>
#include <QPaintEvent>
#include <QPainter>
#include <QPen>
#include <QColor>
#include <QGridLayout>
#include <QList>

#include "KeyBtn.h"

class KeyboardLayout : public QWidget {

private:
    QGridLayout* gLayout = nullptr;
    QList<KeyBtn*> keyList;
    QColor borderColor = QColor(80, 80, 80);
    int borderWidth = 3;

public:
    KeyboardLayout();
    ~KeyboardLayout() override;
    explicit KeyboardLayout(QWidget* parent);
    KeyboardLayout(QWidget* parent, int width, int height);
    [[nodiscard]] const QList<KeyBtn *> &getKeyList() const;
    void setKeyList(const QList<KeyBtn *> &keyList);
    void addKeyBtn(KeyBtn& key, int row, int col);
    void addKeyBtns();
    void setLayoutMargin(int left, int top, int right, int bottom);

protected:
    void paintEvent(QPaintEvent* e) override;

private:
    void setupUI();

};