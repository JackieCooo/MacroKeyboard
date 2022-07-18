#include "HIDUtil.h"

HIDUtil::HIDUtil() {
    devList = new list<HIDDevInterface*>();  // 新建一个链表保存扫描到的设备列表
}

HIDUtil::~HIDUtil() {
    free(devList);
    devList = nullptr;
}

DEV_LIST_T* HIDUtil::FindHidDevice(USHORT vid, USHORT pid) {
    GUID HidGuid;  // 定义一个GUID的结构体HidGuid来保存HID设备的接口类GUID
    HDEVINFO hDevInfoSet;  // 定义一个DEVINFO的句柄hDevInfoSet来保存获取到的设备信息集合句柄
    SP_DEVICE_INTERFACE_DATA DevInterfaceData;  // DevInterfaceData，用来保存设备的驱动接口信息
    PSP_DEVICE_INTERFACE_DETAIL_DATA pDevDetailData;  // 定义一个指向设备详细信息的结构体指针
    HIDD_ATTRIBUTES DevAttributes;  // 定义一个HIDD_ATTRIBUTES的结构体变量，保存设备的属性
    DWORD RequiredSize;  // 定义一个RequiredSize的变量，用来接收需要保存详细信息的缓冲长度
    HANDLE hDevHandle;
    BOOL Result;
    DWORD MemberIndex = 0;  // 定义MemberIndex，表示当前搜索到第几个设备，0表示第一个设备
    HIDP_CAPS Capabilities;
    PHIDP_PREPARSED_DATA HidParsedData;
#ifdef UNICODE
    WCHAR DevicePathName[MAX_DEV_NAME_LEN];
#else
    CHAR DevicePathName[MAX_DEV_NAME_LEN];
#endif

    hDevHandle = INVALID_HANDLE_VALUE;
    if(devList != nullptr) devList->clear();  // 清空列表
    DevInterfaceData.cbSize = sizeof(DevInterfaceData);
    DevAttributes.Size = sizeof(DevAttributes);

    HidD_GetHidGuid(&HidGuid);  // 取得类别

    hDevInfoSet = SetupDiGetClassDevs(&HidGuid, nullptr, nullptr, DIGCF_DEVICEINTERFACE | DIGCF_PRESENT);  // 获取所有在线的设备信息

    while (true) {
        // 1
        Result = SetupDiEnumDeviceInterfaces(hDevInfoSet, nullptr, &HidGuid, MemberIndex, &DevInterfaceData);  // 获取指定序号设备信息

        // 结果非真，说明到设备列表尾
        if (Result == FALSE) {
            break;
        }

        MemberIndex++;

        Result = SetupDiGetDeviceInterfaceDetail(hDevInfoSet, &DevInterfaceData, nullptr, 0, &RequiredSize, nullptr);

        pDevDetailData = (PSP_DEVICE_INTERFACE_DETAIL_DATA) malloc(RequiredSize);
        if (pDevDetailData == nullptr) {
            SetupDiDestroyDeviceInfoList(hDevInfoSet);
            return nullptr;
        }

        pDevDetailData->cbSize = sizeof(SP_DEVICE_INTERFACE_DETAIL_DATA);
        // 2
        Result = SetupDiGetDeviceInterfaceDetail(hDevInfoSet, &DevInterfaceData, pDevDetailData, RequiredSize, nullptr, nullptr);  // 获取设备路径
#ifdef UNICODE
        memcpy(DevicePathName, pDevDetailData->DevicePath, MAX_DEV_NAME_LEN);
#else
        strcpy(DevicePathName, pDevDetailData->DevicePath);
#endif
        free(pDevDetailData);

        if (Result == FALSE) {
            continue;
        }
        // 3
        hDevHandle = CreateFile(DevicePathName, 0, FILE_SHARE_READ | FILE_SHARE_WRITE, nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);  // 开启设备通信

        if (hDevHandle != INVALID_HANDLE_VALUE) {
            Result = HidD_GetAttributes(hDevHandle, &DevAttributes);  // 获取设备属性（PID、VID、版本ID）

            if (Result == FALSE) {
                continue;
            }

            // 找到符合要求的设备
            if (isIDMatched(vid, pid, &DevAttributes)) {
//                cout << "VID: " << DevAttributes.VendorID << " PID: " << DevAttributes.ProductID << " PATH: " << DevicePathName << endl;
                HidD_GetPreparsedData(hDevHandle, &HidParsedData);
                HidP_GetCaps(HidParsedData, &Capabilities);  // 获取设备能力属性
                HidD_FreePreparsedData(HidParsedData);

                WCHAR wcsBuf[MAX_DEV_PRODUCT_STR_LEN];
                CHAR csBuf[MAX_DEV_PRODUCT_STR_LEN];
                HidD_GetProductString(hDevHandle, wcsBuf, MAX_DEV_PRODUCT_STR_LEN);  // 获取产品名
                wcstombs(csBuf, wcsBuf, MAX_DEV_PRODUCT_STR_LEN);  // Unicode转换

                packDevInfo(&DevAttributes, &Capabilities, DevicePathName, csBuf);
            }
            CloseHandle(hDevHandle);
        }
    }

    SetupDiDestroyDeviceInfoList(hDevInfoSet);

    return devList;
}

BOOL HIDUtil::OpenHidDevice(USHORT vid, USHORT pid, BOOL mode) {
    if (devList == nullptr) return FALSE;

    auto res = find_if(devList->begin(), devList->end(), [&](HIDDevInterface* tar){return tar->getVendorId() == vid && tar->getProductId() == pid;});

    if (res == devList->end()) return FALSE;

    auto dev = *res;

    if (hWriteHandle == INVALID_HANDLE_VALUE)
    {
        if (mode)  // 同步
        {
            hWriteHandle = CreateFile(dev->getDevPathName(),
                                      GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, nullptr, OPEN_EXISTING, 0, nullptr);
        }
        else  // 异步
        {
            hWriteHandle = CreateFile(dev->getDevPathName(), GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, nullptr, OPEN_EXISTING, FILE_FLAG_OVERLAPPED, nullptr);
        }
    }
    if (hWriteHandle == INVALID_HANDLE_VALUE) {
        cout << "FAIL: hWriteHandle" << endl;
        return FALSE;
    }

    if (hReadHandle == INVALID_HANDLE_VALUE)
    {
        if (mode)
        {
            hReadHandle = CreateFile(dev->getDevPathName(), GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE, nullptr, OPEN_EXISTING, 0, nullptr);
        }
        else
        {
            hReadHandle = CreateFile(dev->getDevPathName(), GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE, nullptr, OPEN_EXISTING, FILE_FLAG_OVERLAPPED, nullptr);
        }

    }
    if (hReadHandle == INVALID_HANDLE_VALUE) {
        cout << "FAIL: hReadHandle" << endl;
        return FALSE;
    }

    return TRUE;
}

BOOL HIDUtil::SendDataToHidDevice(UCHAR *data, UINT length, UCHAR out_index, BOOL mode) {
    BOOL Result;
    UINT LastError;
    DWORD dwSend;
    OVERLAPPED osWriter = { 0 };

    osWriter.hEvent = CreateEvent(nullptr, TRUE, FALSE, nullptr);
    if (osWriter.hEvent == nullptr)
    {
        return FALSE;
    }

    if (hWriteHandle == INVALID_HANDLE_VALUE)
    {
        return FALSE;
    }

    switch (out_index)
    {
        case 0:
            Result = HidD_SetOutputReport(hWriteHandle, data, length);
            break;

        case 1:
            Result = HidD_SetFeature(hWriteHandle, data, length);
            break;

        case 2:
            if (mode)
            {
                Result = WriteFile(hWriteHandle, data, length, &dwSend, nullptr);
            }
            else
            {
                Result = WriteFile(hWriteHandle, data, length, &dwSend, &osWriter);
            }
            break;

        default:
            return FALSE;
    }

    if (Result == FALSE)
    {
        LastError = GetLastError();
        cout << "FAIL: " << LastError << endl;

        if ((LastError == ERROR_IO_PENDING) || (LastError == ERROR_SUCCESS))
        {
        	return FALSE;
        }
        return FALSE;
    }
    return TRUE;
}

BOOL HIDUtil::GetDataFormHidDevice(UCHAR *data, UINT length, UCHAR in_index, BOOL mode) {
    BOOL Result;
    UINT LastError;
    DWORD dwRead = length;
    OVERLAPPED osReader = { 0 };

    osReader.hEvent = CreateEvent(nullptr, TRUE, FALSE, nullptr);
    if (osReader.hEvent == nullptr)
    {
        return FALSE;
    }
    if (hReadHandle == INVALID_HANDLE_VALUE)
    {
        return FALSE;
    }
    switch (in_index)
    {
        case 0:
            Result = HidD_GetInputReport(hReadHandle, data, length);
            break;

        case 1:
            Result = HidD_GetFeature(hReadHandle, data, length);
            break;

        case 2:
            if (mode)
            {
                Result = ReadFile(hReadHandle, data, length, &dwRead, nullptr);
            }
            else
            {
                SetEvent(osReader.hEvent);
                return TRUE;
            }
            break;

        default:
            return FALSE;
    }

    if (Result == FALSE)
    {
        LastError = GetLastError();
        cout << "FAIL: " << LastError << endl;
        return FALSE;
    }
    return TRUE;
}

BOOL HIDUtil::isIDMatched(USHORT vid, USHORT pid, HIDD_ATTRIBUTES *devAttributes) {
    if (vid && devAttributes->VendorID != vid) return FALSE;
    if (pid && devAttributes->ProductID != pid) return FALSE;
    return TRUE;
}

#ifdef UNICODE
void HIDUtil::packDevInfo(HIDD_ATTRIBUTES* devAttributes, HIDP_CAPS* devCapabilities, WCHAR* devPathName, CHAR* productName) {
#else
void HIDUtil::packDevInfo(HIDD_ATTRIBUTES* devAttributes, HIDP_CAPS* devCapabilities, CHAR* devPathName, CHAR* productName) {
#endif
    auto* devInterface = new HIDDevInterface();

    devInterface->setDevPathName(devPathName);

    devInterface->setVendorId(devAttributes->VendorID);
    devInterface->setProductId(devAttributes->ProductID);
    devInterface->setVersionNumber(devAttributes->VersionNumber);

    devInterface->setProductName(productName);

    devInterface->setFeatureReportByteLength(devCapabilities->FeatureReportByteLength);
    devInterface->setInputReportByteLength(devCapabilities->InputReportByteLength);
    devInterface->setNumberFeatureButtonCaps(devCapabilities->NumberFeatureButtonCaps);
    devInterface->setNumberFeatureDataIndices(devCapabilities->NumberFeatureDataIndices);
    devInterface->setNumberFeatureValueCaps(devCapabilities->NumberFeatureValueCaps);
    devInterface->setNumberInputButtonCaps(devCapabilities->NumberInputButtonCaps);
    devInterface->setNumberInputDataIndices(devCapabilities->NumberInputDataIndices);
    devInterface->setNumberInputValueCaps(devCapabilities->NumberInputValueCaps);
    devInterface->setNumberLinkCollectionNodes(devCapabilities->NumberLinkCollectionNodes);
    devInterface->setNumberOutputButtonCaps(devCapabilities->NumberOutputButtonCaps);
    devInterface->setNumberOutputDataIndices(devCapabilities->NumberOutputDataIndices);
    devInterface->setNumberOutputValueCaps(devCapabilities->NumberOutputValueCaps);
    devInterface->setOutputReportByteLength(devCapabilities->OutputReportByteLength);
    devInterface->setUsage(devCapabilities->Usage);
    devInterface->setUsagePage(devCapabilities->UsagePage);

    if (devList != nullptr) devList->push_back(devInterface);
}

DEV_LIST_T *HIDUtil::getDevList() const {
    return devList;
}
