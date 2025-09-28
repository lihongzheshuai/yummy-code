#include <iostream>
#include <string>
using namespace std;

// 将0-15的数字转换为对应的十六进制字符
// 参数 val: 0-15之间的整数
// 返回值: 对应的十六进制字符（0-9或A-F）
char toHexChar(int val) {
    return (val < 10) ? '0' + val : 'A' + (val - 10);
}

// 将十进制数转换为十六进制字符串
// 参数 num: 待转换的十进制数
// 返回值: 转换后的十六进制字符串（大写，格式如"0x00FF"）
string decimalToHex(int num) {
    // 处理0的特殊情况
    if (num == 0) {
        return "0x0000";
    }
    
    string res;
    // 不断除以16取余，从低位到高位构建十六进制字符串
    while (num > 0) {
        // 取余得到当前位的值（0-15），转换为十六进制字符
        res = toHexChar(num % 16) + res;
        // 除以16，处理下一位
        num /= 16;
    }
    
    // 补齐4位
    while (res.length() < 4) {
        res = "0" + res;
    }
    
    // 添加0x前缀
    return "0x" + res;
}

int main() {
    cout << decimalToHex(254) << endl; // 0x00FE
}