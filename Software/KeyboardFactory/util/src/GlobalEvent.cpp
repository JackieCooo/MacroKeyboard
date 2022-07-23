#include "GlobalEvent.h"

GlobalEvent* GlobalEvent::globalEventPtr = nullptr;
QMutex GlobalEvent::mutex;

/**
  * @brief 全局事件类构造函数
  * @param parent 父类
  * @retval 无
  */
GlobalEvent::GlobalEvent(QObject *parent) : QObject(parent) {
}

/**
  * @brief 获取全局事件类对象
  * @param 无
  * @retval 返回指向全局事件类对象的指针
  */
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
