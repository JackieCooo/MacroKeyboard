#pragma once

#include <QWidget>
#include <QHBoxLayout>
#include <QSizePolicy>
#include <QString>
#include <QLabel>

class InfoPanel : public QWidget {

private:
    QHBoxLayout* hLayout = nullptr;
    QLabel* label = nullptr;
    QLabel* value = nullptr;

public:
    InfoPanel();
    explicit InfoPanel(QWidget* parent);
    InfoPanel(QWidget* parent, const QString& text);
    void setValueText(const QString &valueText);

private:
    void setupUI(const QString& text);

};