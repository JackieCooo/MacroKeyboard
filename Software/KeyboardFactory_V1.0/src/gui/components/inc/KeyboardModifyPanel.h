#pragma once

#include <QWidget>
#include <QHBoxLayout>
#include <QChar>
#include <QString>

#include "KeyboardLayout.h"
#include "KeyBtn.h"

class KeyboardModifyPanel : public QWidget {

private:
    KeyboardLayout* keyboardLayout = nullptr;
    QHBoxLayout* hLayout = nullptr;

public:
    KeyboardModifyPanel();
    explicit KeyboardModifyPanel(QWidget* parent);

private:
    void setupUI();

};