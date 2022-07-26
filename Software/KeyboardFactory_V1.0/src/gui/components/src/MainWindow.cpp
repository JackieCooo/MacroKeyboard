#include "MainWindow.h"

MainWindow::MainWindow() {
    setupUI();
}

void MainWindow::setupUI() {
    this->setFixedSize(800, 600);
    this->setWindowTitle("KeyboardFactory");

    centralWidget = new CentralWidget(this);
    this->setCentralWidget(centralWidget);
}