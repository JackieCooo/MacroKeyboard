#include "HIDDevInterface.h"

USHORT HIDDevInterface::getVendorId() const {
    return VendorID;
}

void HIDDevInterface::setVendorId(USHORT vendorId) {
    VendorID = vendorId;
}

USHORT HIDDevInterface::getProductId() const {
    return ProductID;
}

void HIDDevInterface::setProductId(USHORT productId) {
    ProductID = productId;
}

USHORT HIDDevInterface::getVersionNumber() const {
    return VersionNumber;
}

void HIDDevInterface::setVersionNumber(USHORT versionNumber) {
    VersionNumber = versionNumber;
}

const WCHAR* HIDDevInterface::getDevPathName() const {
    return DevPathName;
}

void HIDDevInterface::setDevPathName(WCHAR* devPathName) {
    DevPathName = devPathName;
}

USAGE HIDDevInterface::getUsage() const {
    return Usage;
}

void HIDDevInterface::setUsage(USAGE usage) {
    Usage = usage;
}

USAGE HIDDevInterface::getUsagePage() const {
    return UsagePage;
}

void HIDDevInterface::setUsagePage(USAGE usagePage) {
    UsagePage = usagePage;
}

USHORT HIDDevInterface::getInputReportByteLength() const {
    return InputReportByteLength;
}

void HIDDevInterface::setInputReportByteLength(USHORT inputReportByteLength) {
    InputReportByteLength = inputReportByteLength;
}

USHORT HIDDevInterface::getOutputReportByteLength() const {
    return OutputReportByteLength;
}

void HIDDevInterface::setOutputReportByteLength(USHORT outputReportByteLength) {
    OutputReportByteLength = outputReportByteLength;
}

USHORT HIDDevInterface::getFeatureReportByteLength() const {
    return FeatureReportByteLength;
}

void HIDDevInterface::setFeatureReportByteLength(USHORT featureReportByteLength) {
    FeatureReportByteLength = featureReportByteLength;
}

USHORT HIDDevInterface::getNumberLinkCollectionNodes() const {
    return NumberLinkCollectionNodes;
}

void HIDDevInterface::setNumberLinkCollectionNodes(USHORT numberLinkCollectionNodes) {
    NumberLinkCollectionNodes = numberLinkCollectionNodes;
}

USHORT HIDDevInterface::getNumberInputButtonCaps() const {
    return NumberInputButtonCaps;
}

void HIDDevInterface::setNumberInputButtonCaps(USHORT numberInputButtonCaps) {
    NumberInputButtonCaps = numberInputButtonCaps;
}

USHORT HIDDevInterface::getNumberInputValueCaps() const {
    return NumberInputValueCaps;
}

void HIDDevInterface::setNumberInputValueCaps(USHORT numberInputValueCaps) {
    NumberInputValueCaps = numberInputValueCaps;
}

USHORT HIDDevInterface::getNumberInputDataIndices() const {
    return NumberInputDataIndices;
}

void HIDDevInterface::setNumberInputDataIndices(USHORT numberInputDataIndices) {
    NumberInputDataIndices = numberInputDataIndices;
}

USHORT HIDDevInterface::getNumberOutputButtonCaps() const {
    return NumberOutputButtonCaps;
}

void HIDDevInterface::setNumberOutputButtonCaps(USHORT numberOutputButtonCaps) {
    NumberOutputButtonCaps = numberOutputButtonCaps;
}

USHORT HIDDevInterface::getNumberOutputValueCaps() const {
    return NumberOutputValueCaps;
}

void HIDDevInterface::setNumberOutputValueCaps(USHORT numberOutputValueCaps) {
    NumberOutputValueCaps = numberOutputValueCaps;
}

USHORT HIDDevInterface::getNumberOutputDataIndices() const {
    return NumberOutputDataIndices;
}

void HIDDevInterface::setNumberOutputDataIndices(USHORT numberOutputDataIndices) {
    NumberOutputDataIndices = numberOutputDataIndices;
}

USHORT HIDDevInterface::getNumberFeatureButtonCaps() const {
    return NumberFeatureButtonCaps;
}

void HIDDevInterface::setNumberFeatureButtonCaps(USHORT numberFeatureButtonCaps) {
    NumberFeatureButtonCaps = numberFeatureButtonCaps;
}

USHORT HIDDevInterface::getNumberFeatureValueCaps() const {
    return NumberFeatureValueCaps;
}

void HIDDevInterface::setNumberFeatureValueCaps(USHORT numberFeatureValueCaps) {
    NumberFeatureValueCaps = numberFeatureValueCaps;
}

USHORT HIDDevInterface::getNumberFeatureDataIndices() const {
    return NumberFeatureDataIndices;
}

void HIDDevInterface::setNumberFeatureDataIndices(USHORT numberFeatureDataIndices) {
    NumberFeatureDataIndices = numberFeatureDataIndices;
}
