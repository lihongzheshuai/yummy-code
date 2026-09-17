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

int main() {

    long long n;
    std::cin >> n; // 从标准输入读取一个整数
    std::vector<long long> result = encode_variant(n); // 对输入的整数进行变长编码

    // 以16进制格式输出编码结果，每个字节宽度为2，前导补0，大写字母
    for (long long i : result) {
        std::cout << std::hex << std::setw(2) << std::setfill('0') << std::uppercase << i << " ";
    }

    return 0; // 程序结束
}