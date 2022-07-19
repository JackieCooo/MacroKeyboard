#pragma once

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QTextBrowser>
#include <QSizePolicy>
#include <QString>
#include <cstdio>

#include "GlobalEvent.h"
#include "HidService.h"

class TransferTab : public QWidget {

    Q_OBJECT

private:
    QVBoxLayout* vLayout = nullptr;
    QLabel* receiveLabel = nullptr;
    QLabel* sendLabel = nullptr;
    QTextBrowser* receiveContent = nullptr;
    QTextBrowser* sendContent = nullptr;

public:
    TransferTab();
    explicit TransferTab(QWidget* parent);

private:
    void setupUI();

private slots:
    void updateReceiveInfo(uint8_t* buf);

};