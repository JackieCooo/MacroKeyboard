#include "../inc/KeyService.h"

void KeyService::comboKey1Pressed() {
    keybd_event(VK_LWIN, 0, 0, 0);
    keybd_event(0x45, 0, 0, 0);

    keybd_event(VK_LWIN, 0, 2, 0);
    keybd_event(0x45, 0, 2, 0);
}

void KeyService::higherVolume() {
    keybd_event(VK_VOLUME_UP, 0, 0, 0);
    keybd_event(VK_VOLUME_UP, 0, 2, 0);
}
