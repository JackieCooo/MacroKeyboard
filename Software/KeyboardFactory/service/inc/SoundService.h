#pragma once

#include <windows.h>
#include <mmdeviceapi.h>
#include <endpointvolume.h>
#include <audioclient.h>

class SoundService {

public:
    static bool setSysVolume(int val);
    static int getSysVolume();
    static void setMute(bool mute);
};