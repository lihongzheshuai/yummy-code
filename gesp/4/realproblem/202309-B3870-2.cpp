/**
 * 题目: 【GESP】C++四级真题 luogu-B3870 [GESP202309 四级] 变长编码
 * 题号: B3870
 * 归属: GESP4级 (202309认证真题)
 * 解法: 解法 2 / 共 2 种解法
 * 博客: https://www.coderli.com/gesp-4-luogu-b3870/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

// 对整数n进行变长编码，返回编码后的字节序列
std::vector<long long> encode_variant(long long n) {
    std::vector<long long> result; // 存储编码结果
    if (n == 0) { // 特殊情况：n为0时，直接返回0
        result.push_back(0);
        return result;
    }
    // 当n不为0时，进行变长编码
    while (n != 0) {
        long long tmp = n & 0b1111111; // 取n的低7位
        n >>= 7; // n右移7位，准备处理下一个字节
        if (n != 0) {
            tmp |= 0b10000000; // 如果后面还有数据，将最高位（第8位）设置为1，表示后续还有字节
        }
        result.push_back(tmp); // 将当前字节加入结果
    }

    return result; // 返回编码后的字节序列
}

// 将一个数字转换为两位十六进制并输出
// 参数 n: 要转换的数字
// 使用字符串索引方式将数字转为对应的十六进制字符
void print_hex(long long n) {
    // 十六进制字符表，用于查找对应字符
    std::string str = "0123456789ABCDEF";
    // 输出高位(n/16)和低位(n%16)对应的十六进制字符
    std::cout << str[n / 16] << str[n % 16];
}

int main() {

    long long n;
    std::cin >> n; // 从标准输入读取一个整数
    std::vector<long long> result = encode_variant(n); // 对输入的整数进行变长编码

    // 以16进制格式输出编码结果，每个字节宽度为2，前导补0，大写字母
    for (long long i : result) {
        print_hex(i);
        std::cout << " ";
    }

    return 0; // 程序结束
}
