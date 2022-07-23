#include "MainWindow.h"

/**
  * @brief 主窗口类构造函数
  * @param 无
  * @retval 无
  */
MainWindow::MainWindow() {
    setupUI();
}

/**
  * @brief 主窗口关闭事件处理函数
  * @param event 事件对象
  * @retval 无
  */
void MainWindow::closeEvent(QCloseEvent *event) {
    ::raise(SIGINT);  // 发送主窗口关闭信号
    event->accept();
}

/**
  * @brief 初始化UI
  * @param 无
  * @retval 无
  */
void MainWindow::setupUI() {
    mainFrame = new QWidget(this);

    vLayout = new QVBoxLayout(mainFrame);
    mainFrame->setLayout(vLayout);

    topPanel = new TopPanel(mainFrame);
    vLayout->addWidget(topPanel);

    tabWidget = new TabWidget(mainFrame);
    vLayout->addWidget(tabWidget);

    this->setCentralWidget(mainFrame);
}
