#include <algorithm>
#include <iostream>

// 数组大小开到 10^6 + 5，题目要求乘数不超过 10^2000，数组足够大
const int N = 10e5 + 5;
// a 数组存放被乘数，b 数组存放乘数，c 数组存放乘积
int a[N], b[N], c[N];

// 高精度乘法函数，传入两个大整数字符串，返回它们的乘积字符串
std::string big_multi(std::string num1, std::string num2) {
    std::string res = "";
    int n = num1.size(), m = num2.size();

    // 逆序将字符串 num1 的每一位数字存入数组 a
    // 使得字符串末尾（个位）存放在 a[0]，十位存放在 a[1]，以此类推
    for (int i = n - 1; i >= 0; i--) {
        a[n - i - 1] = num1[i] - '0';
    }
    // 逆序将字符串 num2 的每一位数字存入数组 b，个位数对应 b[0]
    for (int i = m - 1; i >= 0; i--) {
        b[m - i - 1] = num2[i] - '0';
    }

    // 模拟竖式乘法运算的核心过程
    // a 的第 i 位乘以 b 的第 j 位，乘积应该累加到 c 的第 i+j 位上
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            c[i + j] += a[i] * b[j];
        }
    }

    // 两个数相乘，乘积的总位数最多为它们的位数之和 (n + m)
    int len = n + m;
    // 处理统一进位：遍历乘积数组 c，如果当前位满 10，则向高位进位
    for (int i = 0; i < len; i++) {
        if (c[i] >= 10) {
            c[i + 1] += c[i] / 10;  // 向前（高位）进位
            c[i] %= 10;             // 当前位保留余数（个数）
        }
    }

    // 去除前导零：结果可能没有达到 n + m 位，除了数字 0
    // 本身（至少保留一位），把最高位多余的 0 去掉
    while (len > 1 && c[len - 1] == 0) {
        len--;
    }

    // 从高位到低位，将计算完毕整数逆序拼接回字符串
    for (int i = len - 1; i >= 0; i--) {
        res += c[i] + '0';
    }

    return res;
}

int main() {
    std::string a, b;
    // 读入两个非常大的非负整数字符串
    std::cin >> a >> b;
    // 调用大整数乘法计算函数并输出结果
    std::cout << big_multi(a, b) << std::endl;
    return 0;
}