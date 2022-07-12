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

    QString labelText = "";
    QString valueText = "";

public:
    InfoPanel();
    explicit InfoPanel(QWidget* parent);
    InfoPanel(QWidget* parent, const QString& text);
    [[nodiscard]] const QString &getLabelText() const;
    void setLabelText(const QString &labelText);
    [[nodiscard]] const QString &getValueText() const;
    void setValueText(const QString &valueText);

private:
    void setupUI();

};