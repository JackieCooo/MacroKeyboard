#pragma once

#include <iostream>
#include <list>
#include <cstring>
#include <windows.h>

#include "HIDDevInterface.h"

extern "C" {
#include "setupapi.h"
#include "hidsdi.h"
}

/* 选项 */
#define ANY_VID 0
#define ANY_PID 0

/* 文件打开模式 */
#define MODE_SYNC TRUE
#define MODE_ASYNC FALSE

/* HID接收方式 */
#define READ_REPORT 0
#define READ_FEATURE 1
#define READ_INTERRUPT 2

/* HID发送方式 */
#define WRITE_REPORT 0
#define WRITE_FEATURE 1
#define WRITE_INTERRUPT 2

using namespace std;

typedef list<HIDDevInterface*> DEV_LIST_T;

class HIDUtil {

private:
    DEV_LIST_T* devList = nullptr;
    HANDLE hWriteHandle = INVALID_HANDLE_VALUE;
    HANDLE hReadHandle = INVALID_HANDLE_VALUE;

public:
    HIDUtil();
    ~HIDUtil();
    DEV_LIST_T* FindHidDevice(USHORT vid, USHORT pid);
    BOOL OpenHidDevice(USHORT vid, USHORT pid, BOOL mode);
    BOOL SendDataToHidDevice(UCHAR *data, UINT length, UCHAR out_index, BOOL mode);
    BOOL GetDataFormHidDevice(UCHAR *data, UINT length, UCHAR in_index, BOOL mode);
    DEV_LIST_T *getDevList() const;

private:
    static BOOL isIDMatched(USHORT vid, USHORT pid, HIDD_ATTRIBUTES* devAttributes);

#ifdef UNICODE
    void packDevInfo(HIDD_ATTRIBUTES* devAttributes, HIDP_CAPS* devCapabilities, WCHAR* devPathName, CHAR* productName);
#else
    void packDevInfo(HIDD_ATTRIBUTES* devAttributes, HIDP_CAPS* devCapabilities, CHAR* devPathName, CHAR* productName);
#endif

};
