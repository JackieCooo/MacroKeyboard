#include "VirtualKeyList.h"

/**
  * @brief 虚拟键列表类构造函数
  * @param 无
  * @retval 无
  */
VirtualKeyList::VirtualKeyList() {
    setupList();
}

/**
  * @brief 初始化列表
  * @param 无
  * @retval 无
  */
void VirtualKeyList::setupList() {
    this->resize(256);

    (*this)[0] = "(无)";
    (*this)[1] = "鼠标左键";
    (*this)[2] = "鼠标右键";
    (*this)[3] = "取消处理";
    (*this)[4] = "鼠标中键";
    (*this)[5] = "鼠标按钮1";
    (*this)[6] = "鼠标按钮2";
    (*this)[7] = "Undefined";
    (*this)[8] = "空格键";
    (*this)[9] = "制表键";
    (*this)[10] = "Undefined";
    (*this)[11] = "Undefined";
    (*this)[12] = "清除键";
    (*this)[13] = "回车键";
    (*this)[14] = "Undefined";
    (*this)[15] = "Undefined";
    (*this)[16] = "SHIFT键";
    (*this)[17] = "CTRL键";
    (*this)[18] = "ALT键";
    (*this)[19] = "暂停键";
    (*this)[20] = "大小写切换键";
    (*this)[21] = "Undefined";
    (*this)[22] = "Undefined";
    (*this)[23] = "Undefined";
    (*this)[24] = "Undefined";
    (*this)[25] = "Undefined";
    (*this)[26] = "Undefined";
    (*this)[27] = "ESC键";
    (*this)[28] = "Undefined";
    (*this)[29] = "Undefined";
    (*this)[30] = "Undefined";
    (*this)[31] = "Undefined";
    (*this)[32] = "SPACEBAR键";
    (*this)[33] = "PAGE UP键";
    (*this)[34] = "PAGE DOWN键";
    (*this)[35] = "END键";
    (*this)[36] = "HOME键";
    (*this)[37] = "左箭头键";
    (*this)[38] = "上箭头键";
    (*this)[39] = "右箭头键";
    (*this)[40] = "下箭头键";
    (*this)[41] = "选择键";
    (*this)[42] = "打印键";
    (*this)[43] = "执行键";
    (*this)[44] = "截屏键";
    (*this)[45] = "插入键";
    (*this)[46] = "删除键";
    (*this)[47] = "帮助键";
    (*this)[48] = "0";
    (*this)[49] = "1";
    (*this)[50] = "2";
    (*this)[51] = "3";
    (*this)[52] = "4";
    (*this)[53] = "5";
    (*this)[54] = "6";
    (*this)[55] = "7";
    (*this)[56] = "8";
    (*this)[57] = "9";
    (*this)[58] = "Undefined";
    (*this)[59] = "Undefined";
    (*this)[60] = "Undefined";
    (*this)[61] = "Undefined";
    (*this)[62] = "Undefined";
    (*this)[63] = "Undefined";
    (*this)[64] = "Undefined";
    (*this)[65] = "A";
    (*this)[66] = "B";
    (*this)[67] = "C";
    (*this)[68] = "D";
    (*this)[69] = "E";
    (*this)[70] = "F";
    (*this)[71] = "G";
    (*this)[72] = "H";
    (*this)[73] = "I";
    (*this)[74] = "J";
    (*this)[75] = "K";
    (*this)[76] = "L";
    (*this)[77] = "M";
    (*this)[78] = "N";
    (*this)[79] = "O";
    (*this)[80] = "P";
    (*this)[81] = "Q";
    (*this)[82] = "R";
    (*this)[83] = "S";
    (*this)[84] = "T";
    (*this)[85] = "U";
    (*this)[86] = "V";
    (*this)[87] = "W";
    (*this)[88] = "X";
    (*this)[89] = "Y";
    (*this)[90] = "Z";
    (*this)[91] = "左WIN键";
    (*this)[92] = "右WIN键";
    (*this)[93] = "应用键";
    (*this)[94] = "Undefined";
    (*this)[95] = "电脑休眠键";
    (*this)[96] = "数字键盘0";
    (*this)[97] = "数字键盘1";
    (*this)[98] = "数字键盘2";
    (*this)[99] = "数字键盘3";
    (*this)[100] = "数字键盘4";
    (*this)[101] = "数字键盘5";
    (*this)[102] = "数字键盘6";
    (*this)[103] = "数字键盘7";
    (*this)[104] = "数字键盘8";
    (*this)[105] = "数字键盘9";
    (*this)[106] = "多功能键";
    (*this)[107] = "加号键";
    (*this)[108] = "分隔符键";
    (*this)[109] = "减号键";
    (*this)[110] = "小数点键";
    (*this)[111] = "除号键";
    (*this)[112] = "F1";
    (*this)[113] = "F2";
    (*this)[114] = "F3";
    (*this)[115] = "F4";
    (*this)[116] = "F5";
    (*this)[117] = "F6";
    (*this)[118] = "F7";
    (*this)[119] = "F8";
    (*this)[120] = "F9";
    (*this)[121] = "F10";
    (*this)[122] = "F11";
    (*this)[123] = "F12";
    (*this)[124] = "F13";
    (*this)[125] = "F14";
    (*this)[126] = "F15";
    (*this)[127] = "F16";
    (*this)[128] = "F17";
    (*this)[129] = "F18";
    (*this)[130] = "F19";
    (*this)[131] = "F20";
    (*this)[132] = "F21";
    (*this)[133] = "F22";
    (*this)[134] = "F23";
    (*this)[135] = "F24";
    (*this)[136] = "Undefined";
    (*this)[137] = "Undefined";
    (*this)[138] = "Undefined";
    (*this)[139] = "Undefined";
    (*this)[140] = "Undefined";
    (*this)[141] = "Undefined";
    (*this)[142] = "Undefined";
    (*this)[143] = "Undefined";
    (*this)[144] = "数字键盘锁定键";
    (*this)[145] = "滚动锁定键";
    (*this)[146] = "Undefined";
    (*this)[147] = "Undefined";
    (*this)[148] = "Undefined";
    (*this)[149] = "Undefined";
    (*this)[150] = "Undefined";
    (*this)[151] = "Undefined";
    (*this)[152] = "Undefined";
    (*this)[153] = "Undefined";
    (*this)[154] = "Undefined";
    (*this)[155] = "Undefined";
    (*this)[156] = "Undefined";
    (*this)[157] = "Undefined";
    (*this)[158] = "Undefined";
    (*this)[159] = "Undefined";
    (*this)[160] = "左SHIFT键";
    (*this)[161] = "右SHIFT键";
    (*this)[162] = "左CTRL键";
    (*this)[163] = "右CTRL键";
    (*this)[164] = "左ALT键";
    (*this)[165] = "右ALT键";
    (*this)[166] = "浏览器返回键";
    (*this)[167] = "浏览器前进键";
    (*this)[168] = "浏览器刷新键";
    (*this)[169] = "浏览器停止键";
    (*this)[170] = "浏览器搜索键";
    (*this)[171] = "浏览器收藏键";
    (*this)[172] = "浏览器HOME键";
    (*this)[173] = "静音键";
    (*this)[174] = "音量调小键";
    (*this)[175] = "音量调大键";
    (*this)[176] = "下一首键";
    (*this)[177] = "上一首键";
    (*this)[178] = "停止播放键";
    (*this)[179] = "暂停播放键";
    (*this)[180] = "邮件发送键";
    (*this)[181] = "媒体选择键";
    (*this)[182] = "启动应用1键";
    (*this)[183] = "启动应用2键";
    (*this)[184] = ";:键";
    (*this)[185] = "+键";
    (*this)[186] = ",键";
    (*this)[187] = "-键";
    (*this)[188] = ".键";
    (*this)[189] = "/?键";
    (*this)[190] = "`~键";
    (*this)[191] = "Undefined";
    (*this)[192] = "Undefined";
    (*this)[193] = "Undefined";
    (*this)[194] = "Undefined";
    (*this)[195] = "Undefined";
    (*this)[196] = "Undefined";
    (*this)[197] = "Undefined";
    (*this)[198] = "Undefined";
    (*this)[199] = "Undefined";
    (*this)[200] = "Undefined";
    (*this)[201] = "Undefined";
    (*this)[202] = "Undefined";
    (*this)[203] = "Undefined";
    (*this)[204] = "Undefined";
    (*this)[205] = "Undefined";
    (*this)[206] = "Undefined";
    (*this)[207] = "Undefined";
    (*this)[208] = "Undefined";
    (*this)[209] = "Undefined";
    (*this)[210] = "Undefined";
    (*this)[211] = "Undefined";
    (*this)[212] = "Undefined";
    (*this)[213] = "Undefined";
    (*this)[214] = "Undefined";
    (*this)[215] = "Undefined";
    (*this)[216] = "Undefined";
    (*this)[217] = "Undefined";
    (*this)[218] = "Undefined";
    (*this)[219] = "[{键";
    (*this)[220] = "\\|键";
    (*this)[221] = "]}键";
    (*this)[222] = "\"\'键";
    (*this)[223] = "Undefined";
    (*this)[224] = "Undefined";
    (*this)[225] = "Undefined";
    (*this)[226] = "Undefined";
    (*this)[227] = "Undefined";
    (*this)[228] = "Undefined";
    (*this)[229] = "Undefined";
    (*this)[230] = "Undefined";
    (*this)[231] = "Undefined";
    (*this)[232] = "Undefined";
    (*this)[233] = "Undefined";
    (*this)[234] = "Undefined";
    (*this)[235] = "Undefined";
    (*this)[236] = "Undefined";
    (*this)[237] = "Undefined";
    (*this)[238] = "Undefined";
    (*this)[239] = "Undefined";
    (*this)[240] = "Undefined";
    (*this)[241] = "Undefined";
    (*this)[242] = "Undefined";
    (*this)[243] = "Undefined";
    (*this)[244] = "Undefined";
    (*this)[245] = "Undefined";
    (*this)[246] = "Attn键";
    (*this)[247] = "CrSel键";
    (*this)[248] = "ExSel键";
    (*this)[249] = "释放EOF键";
    (*this)[250] = "播放键";
    (*this)[251] = "缩放键";
    (*this)[252] = "Undefined";
    (*this)[253] = "PA1键";
    (*this)[254] = "清除键";
    (*this)[255] = "Undefined";

}

/**
  * @brief 由虚拟键名查找虚拟键码
  * @param name 虚拟键名
  * @retval 返回虚拟键码
  */
uint8_t VirtualKeyList::keyCode(const QString &name) {
    for (int i = 0; i < 256; ++i) {
        if ((*this)[i] == name) return i;
    }
    return 0;
}

/**
  * @brief 有虚拟键码查找虚拟键名
  * @param keyCode 虚拟键码
  * @retval 返回虚拟键名
  */
QString& VirtualKeyList::keyName(uint8_t keyCode) {
    return (*this)[keyCode];
}
