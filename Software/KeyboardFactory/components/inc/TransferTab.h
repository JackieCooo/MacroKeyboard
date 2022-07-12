#pragma once

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QTextBrowser>
#include <QSizePolicy>

class TransferTab : public QWidget {

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

};