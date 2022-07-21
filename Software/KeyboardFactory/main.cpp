#include <QApplication>

#include "MainWindow.h"
#include "HidService.h"
#include "IniHandler.h"
#include "VirtualKeyList.h"

HidService* hidService = nullptr;
IniHandler* iniHandler = nullptr;
VirtualKeyList* virtualKeyList = nullptr;

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    // 创建虚拟键码表
    virtualKeyList = new VirtualKeyList();

    // 初始化系统本地配置服务
    iniHandler = new IniHandler();

    MainWindow mainWindow;
    mainWindow.resize(800, 600);
    mainWindow.show();

    // 启动设备扫描线程
    hidService = new HidService();
    hidService->startScanService();

    return QApplication::exec();
}
