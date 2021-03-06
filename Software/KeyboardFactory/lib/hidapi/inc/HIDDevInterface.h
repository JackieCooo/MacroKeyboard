#pragma once

#include <string>
#include <windows.h>

extern "C" {
#include "setupapi.h"
#include "hidsdi.h"
}

/* 配置 */
#define MAX_DEV_NAME_LEN 512
#define MAX_DEV_PRODUCT_STR_LEN 128

using namespace std;

class HIDDevInterface {

private:
    USHORT VendorID;
    USHORT ProductID;
    USHORT VersionNumber;
    CHAR ProductName[MAX_DEV_PRODUCT_STR_LEN];
#ifdef UNICODE
    WCHAR DevPathName[MAX_DEV_NAME_LEN];
#else
    CHAR DevPathName[MAX_DEV_NAME_LEN];
#endif
    USAGE Usage;
    USAGE UsagePage;
    USHORT InputReportByteLength;
    USHORT OutputReportByteLength;
    USHORT FeatureReportByteLength;
    USHORT NumberLinkCollectionNodes;
    USHORT NumberInputButtonCaps;
    USHORT NumberInputValueCaps;
    USHORT NumberInputDataIndices;
    USHORT NumberOutputButtonCaps;
    USHORT NumberOutputValueCaps;
    USHORT NumberOutputDataIndices;
    USHORT NumberFeatureButtonCaps;
    USHORT NumberFeatureValueCaps;
    USHORT NumberFeatureDataIndices;

public:
    HIDDevInterface() = default;
    USHORT getVendorId() const;
    void setVendorId(USHORT vendorId);
    USHORT getProductId() const;
    void setProductId(USHORT productId);
    const CHAR *getProductName() const;
    void setProductName(const CHAR* productName);
    USHORT getVersionNumber() const;
    void setVersionNumber(USHORT versionNumber);

#ifdef UNICODE
    const WCHAR* getDevPathName() const;
    void setDevPathName(WCHAR* devPathName);
#else
    const CHAR *getDevPathName() const;
    void setDevPathName(CHAR* devPathName);
#endif
    USAGE getUsage() const;
    void setUsage(USAGE usage);
    USAGE getUsagePage() const;
    void setUsagePage(USAGE usagePage);
    USHORT getInputReportByteLength() const;
    void setInputReportByteLength(USHORT inputReportByteLength);
    USHORT getOutputReportByteLength() const;
    void setOutputReportByteLength(USHORT outputReportByteLength);
    USHORT getFeatureReportByteLength() const;
    void setFeatureReportByteLength(USHORT featureReportByteLength);
    USHORT getNumberLinkCollectionNodes() const;
    void setNumberLinkCollectionNodes(USHORT numberLinkCollectionNodes);
    USHORT getNumberInputButtonCaps() const;
    void setNumberInputButtonCaps(USHORT numberInputButtonCaps);
    USHORT getNumberInputValueCaps() const;
    void setNumberInputValueCaps(USHORT numberInputValueCaps);
    USHORT getNumberInputDataIndices() const;
    void setNumberInputDataIndices(USHORT numberInputDataIndices);
    USHORT getNumberOutputButtonCaps() const;
    void setNumberOutputButtonCaps(USHORT numberOutputButtonCaps);
    USHORT getNumberOutputValueCaps() const;
    void setNumberOutputValueCaps(USHORT numberOutputValueCaps);
    USHORT getNumberOutputDataIndices() const;
    void setNumberOutputDataIndices(USHORT numberOutputDataIndices);
    USHORT getNumberFeatureButtonCaps() const;
    void setNumberFeatureButtonCaps(USHORT numberFeatureButtonCaps);
    USHORT getNumberFeatureValueCaps() const;
    void setNumberFeatureValueCaps(USHORT numberFeatureValueCaps);
    USHORT getNumberFeatureDataIndices() const;
    void setNumberFeatureDataIndices(USHORT numberFeatureDataIndices);

};
