#pragma once

#include <QWidget>
#include <QObject>
#include <QVBoxLayout>

class StyleComboBoxPopUp : public QWidget {

    Q_OBJECT

private:

public:
    StyleComboBoxPopUp();
    explicit StyleComboBoxPopUp(QWidget* parent);

private:
    void setupUI();

public slots:
    void showPopup();
    void hidePopup();

};