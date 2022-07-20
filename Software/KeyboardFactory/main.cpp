#include <QApplication>

#include "MainWindow.h"
#include "HidService.h"
#include "IniHandler.h"

HidService* hidService = nullptr;
IniHandler* iniHandler = nullptr;

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    MainWindow mainWindow;
    mainWindow.resize(800, 600);
    mainWindow.show();

    // 初始化系统本地配置服务
    iniHandler = new IniHandler();

    // 启动设备扫描线程
    hidService = new HidService();
    hidService->startScanService();

    return QApplication::exec();
}
