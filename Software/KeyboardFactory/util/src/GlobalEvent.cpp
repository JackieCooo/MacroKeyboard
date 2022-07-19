#include "GlobalEvent.h"

GlobalEvent* GlobalEvent::globalEventPtr = nullptr;
QMutex GlobalEvent::mutex;

GlobalEvent::GlobalEvent(QObject *parent) : QObject(parent) {
}

GlobalEvent* GlobalEvent::getInstance() {
    if (globalEventPtr == nullptr) {
        mutex.lock();
        if (globalEventPtr == nullptr) {
            globalEventPtr = new GlobalEvent;
        }
        mutex.unlock();
    }
    return globalEventPtr;
}
