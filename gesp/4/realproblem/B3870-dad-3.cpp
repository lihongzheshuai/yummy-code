#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>

// 对整数n进行变长编码，返回编码后的字节序列
// 变长编码方式：每7位二进制为一组，最高位为1表示后续还有字节，最高位为0表示最后一个字节
std::vector<std::string> encode_variant(long long n) {
    std::vector<std::string> result;  // 存储编码结果
    if (n == 0) { // 特殊情况：n为0时，直接返回"00"
        result.push_back("00");
        return result;
    }
    // 将n转换为二进制字符串（高位在前，低位在后）
    std::string tmp;
    while (n != 0) {
        // 每次取最低位，拼接到tmp前面
        tmp = char(n % 2 + '0') + tmp;
        n /= 2;
    }

    int l_tmp = tmp.length(); // 二进制字符串长度

    if (l_tmp <= 7) {
        // 如果二进制长度不超过7位，直接补在后面，最高位为0，表示这是最后一个字节
        result.push_back('0' + tmp);
    } else {
        // 如果超过7位，需要分组处理
        int f_length = l_tmp % 7; // 头部不足7位的长度
        int idx = l_tmp - 7;      // 从倒数第7位开始分组
        // 从高位到低位，每7位为一组，最高位为1，表示后续还有字节
        while (idx >= 0) {
            std::string cur_str = tmp.substr(idx, 7); // 取7位
            result.push_back('1' + cur_str);          // 最高位为1
            idx -= 7;
        }
        // 如果有头部不足7位的部分，需要补0到7位，最高位为0，表示最后一个字节
        if (f_length != 0) {
            std::string tmp_str = tmp.substr(0, f_length); // 取头部不足7位
            // 补0到7位
            for (int j = 0; j < 7 - f_length; j++) {
                tmp_str = '0' + tmp_str;
            }
            result.push_back('0' + tmp_str); // 最高位为0
        }
    }

    return result;  // 返回编码后的字节序列
}

int main() {
    long long n;
    std::cin >> n;  // 从标准输入读取一个整数
    // 对输入的整数进行变长编码
    std::vector<std::string> result = encode_variant(n);

    // 以16进制格式输出编码结果，每个字节宽度为2，前导补0，大写字母
    for (std::string str : result) {
        // 将二进制字符串转为整数，再以16进制输出
        printf("%02X", stoll(str, nullptr, 2));
        std::cout << " ";
    }

    return 0;  // 程序结束
}