/**
 * 题目: 【NOIP】1999真题解析 luogu-P1015 回文数 | GESP四、五级以上可练习
 * 题号: P1015
 * 归属: GESP5级
 * 博客: https://www.coderli.com/noip-1999-luogu-p1015/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <algorithm>
#include <iostream>

// 字符转数字：支持 2~10 进制以及 16 进制的字符转化为对应的整数值
int char_to_int(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'A' && c <= 'F') return c - 'A' + 10;
    if (c >= 'a' && c <= 'f') return c - 'a' + 10;
    return 0;
}

// 数字转字符：将高精度计算产生的值（0~15）转化为对应的字符表示
char int_to_char(int v) {
    if (v >= 0 && v <= 9) return '0' + v;
    if (v >= 10 && v <= 15) return 'A' + (v - 10);
    return '0';
}

// 检查给定的字符串是否为回文串
bool check(std::string str) {
    for (int i = 0; i < str.length(); i++) {
        // 双指针思想，判断首尾对应位置的字符是否相同
        if (str[i] != str[str.length() - 1 - i]) {
            return false; // 只要有一位不同，立刻返回不是回文串
        }
    }
    return true;
}

// N 进制下的高精度加法运算
std::string big_sum(std::string str1, std::string str2, int n) {
    std::string res = "";
    int les = std::max(str1.length(), str2.length());
    int carry = 0; // 进位标记

    // 从个位（字符串的尾部）开始，遂位进行加法运算
    for (int i = 0; i < les; i++) {
        // 分别获取倒数第 i 位的值，如果超出了长度则记为 0
        int v1 =
            i < str1.length() ? char_to_int(str1[str1.length() - 1 - i]) : 0;
        int v2 =
            i < str2.length() ? char_to_int(str2[str2.length() - 1 - i]) : 0;

        // 将对应位相加并带上进位
        int tmp = v1 + v2 + carry;
        res += int_to_char(tmp % n); // 取余 n 作为当前位的值，保存回字符串
        carry = tmp / n;             // 除以 n 计算向高位的进位
    }

    // 如果最高位计算完成后还有进位，需要额外补上
    if (carry != 0) {
        res += int_to_char(carry);
    }

    // 因为生成字符串是从低位逐步加到高位的字符，所以最终需要反转才是正确结果
    std::reverse(res.begin(), res.end());
    return res;
}

int main() {
    int N;
    std::string M;
    std::cin >> N >> M; // 读取进制 N 和原始数值字符串 M

    const int limit = 30; // 题目要求的最大步数限制
    std::string str = M;

    // 特判：如果初始状态就是一个回文数，则经过 0 步就可以得到
    if (check(str)) {
        std::cout << "STEP=0\n";
        return 0;
    }

    // 最多进行 limit (30) 次加法尝试
    for (int i = 1; i <= limit; i++) {
        std::string tmp = str;
        // 将原序列反转，得到从右向左读的数
        std::reverse(tmp.begin(), tmp.end());

        // 调用 N 进制的高精度加法
        str = big_sum(str, tmp, N);

        // 检查新生成的数字是否是回文数
        if (check(str)) {
            // 输出得到回文数字所需的步数，然后直接结束程序
            std::cout << "STEP=" << i << "\n";
            return 0;
        }
    }

    // 超过 30 步仍未得到回文数，输出不可能
    std::cout << "Impossible!\n";
    return 0;
}
