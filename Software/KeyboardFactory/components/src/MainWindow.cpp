#include "MainWindow.h"

MainWindow::MainWindow() {
    setupUI();
}

void MainWindow::closeEvent(QCloseEvent *event) {
    ::raise(SIGINT);  // 发送主窗口关闭信号
    event->accept();
}

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
