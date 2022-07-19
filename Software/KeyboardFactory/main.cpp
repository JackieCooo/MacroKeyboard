#include <QApplication>

#include "MainWindow.h"
#include "HidService.h"

HidService* hidService = nullptr;

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    MainWindow mainWindow;
    mainWindow.resize(800, 600);
    mainWindow.show();

    // 主窗口初始化完毕，启动设备扫描线程
    hidService = new HidService();
    hidService->startScanService();

    return QApplication::exec();
}
