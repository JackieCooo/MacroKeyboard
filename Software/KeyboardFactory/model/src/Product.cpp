#include "Product.h"

/**
  * @brief 获取产品名
  * @param 无
  * @retval 返回产品名
  */
const QString &Product::getName() const {
    return name;
}

/**
  * @brief 设置产品名
  * @param name 产品名
  * @retval 无
  */
void Product::setName(const QString &name) {
    this->name = name;
}

/**
  * @brief 获取PID
  * @param 无
  * @retval 返回PID
  */
uint16_t Product::getPid() const {
    return pid;
}

/**
  * @brief 设置PID
  * @param pid PID
  * @retval 无
  */
void Product::setPid(uint16_t pid) {
    this->pid = pid;
}

/**
  * @brief 产品类构造函数
  * @param name 产品名
  * @param pid PID
  * @retval 无
  */
Product::Product(const QString &name, uint16_t pid) : name(name), pid(pid) {}

/**
  * @brief 获取键盘总键数
  * @param 无
  * @retval 返回键盘总键数
  */
uint8_t Product::getKeys() const {
    return keys;
}

/**
  * @brief 设置键盘总键数
  * @param keys 键盘总键数
  * @retval 无
  */
void Product::setKeys(uint8_t keys) {
    this->keys = keys;
}
