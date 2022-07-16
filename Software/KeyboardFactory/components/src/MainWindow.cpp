#include "MainWindow.h"

MainWindow::MainWindow() {
    setupUI();
}

void MainWindow::setupUI() {
    hidService = new HIDService();

    mainFrame = new QWidget(this);

    vLayout = new QVBoxLayout(mainFrame);
    mainFrame->setLayout(vLayout);

    topPanel = new TopPanel(mainFrame);
    topPanel->setHIDService(hidService);
    vLayout->addWidget(topPanel);

    tabWidget = new TabWidget(mainFrame);
    vLayout->addWidget(tabWidget);

    this->setCentralWidget(mainFrame);

    hidService->start();
}

HIDService *MainWindow::getHidService() const {
    return hidService;
}
