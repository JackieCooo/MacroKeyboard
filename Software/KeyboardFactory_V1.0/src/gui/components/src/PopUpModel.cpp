#include "PopUpModel.h"

const QString &PopUpItemModel::getText() const {
    return text;
}

void PopUpItemModel::setText(const QString &text) {
    this->text = text;
}

const QVariant &PopUpItemModel::getUserData() const {
    return userData;
}

void PopUpItemModel::setUserData(const QVariant &userData) {
    this->userData = userData;
}

const QWidget* PopUpItemModel::getTarget() const {
    return this->target;
}

void PopUpItemModel::setTarget(QWidget *tar) {
    this->target = tar;
}

PopUpItemModel::PopUpItemModel(QWidget *target, const QString& text, const QVariant& userData) {
    this->target = target;
    this->text = text;
    this->userData = userData;
}

int PopUpModel::count() const {
    return popUpItems.size();
}

void PopUpModel::insertItem(int index, PopUpItemModel *item) {
    popUpItems.insert(index, item);
    emit itemsChanged();
}

void PopUpModel::addItem(PopUpItemModel *item) {
    popUpItems.push_back(item);
    emit itemsChanged();
}

int PopUpModel::indexOf(QWidget *tar) {
    int i = 0;
    for (auto j : popUpItems) {
        if (j->getTarget() == tar) return i;
        ++i;
    }
    return -1;
}

PopUpItemModel* PopUpModel::itemOf(QWidget *tar) {
    auto res = find_if(popUpItems.begin(), popUpItems.end(), [&](const PopUpItemModel* i){return i->getTarget() == tar;});
    if (res == popUpItems.end()) return nullptr;
    return *res;
}

PopUpItemModel* PopUpModel::itemOf(int index) {
    if (index < 0 || index >= popUpItems.size()) return nullptr;
    return popUpItems.takeAt(index);
}
