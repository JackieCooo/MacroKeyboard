#pragma once

#include <algorithm>
#include <QObject>
#include <QList>
#include <QString>
#include <QVariant>

using namespace std;

class PopUpItemModel : public QObject {

    Q_OBJECT

private:
    QWidget* target = nullptr;
    QString text;
    QVariant userData;

public:
    PopUpItemModel() = default;
    explicit PopUpItemModel(QWidget *target, const QString& text = nullptr, const QVariant& userData = QVariant());
    [[nodiscard]] const QString &getText() const;
    void setText(const QString &text);
    [[nodiscard]] const QVariant &getUserData() const;
    void setUserData(const QVariant &userData);
    [[nodiscard]] const QWidget* getTarget() const;
    void setTarget(QWidget* tar);

};

class PopUpModel : public QObject {

    Q_OBJECT

private:
    QList<PopUpItemModel*> popUpItems;

public:
    PopUpModel() = default;
    [[nodiscard]] int count() const;
    void insertItem(int index, PopUpItemModel* item);
    void addItem(PopUpItemModel* item);
    int indexOf(QWidget* tar);
    PopUpItemModel* itemOf(QWidget* tar);
    PopUpItemModel* itemOf(int index);

signals:
    void itemsChanged();

};