#include "MainWindow.h"

MainWindow::MainWindow() {
    setupUI();
}

void MainWindow::setupUI() {
    mainFrame = new QWidget(this);

    vLayout = new QVBoxLayout(mainFrame);
    mainFrame->setLayout(vLayout);

    topPanel = new TopPanel(mainFrame);

    tabWidget = new TabWidget(mainFrame);
}
