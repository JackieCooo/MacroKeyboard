#pragma once

#include <QKeyEvent>
#include <windows.h>
#pragma comment(lib, "user32.lib")

class KeyService {

private:

public:
    KeyService() = default;
    void comboKey1Pressed();
    void higherVolume();
};