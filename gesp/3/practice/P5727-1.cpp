/**
 * 题目: 【GESP】C++三级练习 luogu-P5727 【深基5.例3】冰雹猜想
 * 题号: P5727
 * 归属: GESP3级
 * 解法: 解法 1 / 共 2 种解法
 * 博客: https://www.coderli.com/gesp-3-luogu-p5727/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>

// 定义一个大小为105的整型数组，用于存储冰雹猜想的数列变化过程
// 初始化所有元素为0
int result_ary[105] = {0};
int main() {
    // 读取输入的数字
    int n;
    std::cin >> n;
    // 将初始数字存入数组第一个位置
    result_ary[0] = n;
    // 用于记录数组当前位置的索引
    int idx = 1;

    // 根据冰雹猜想规则不断变换数字，直到得到1
    while (n != 1) {
        // 如果是偶数，除以2
        if (n % 2 == 0) {
            n /= 2;
        }
        // 如果是奇数，乘3加1
        else {
            n = n * 3 + 1;
        }
        // 将变换后的数字存入数组
        result_ary[idx] = n;
        idx++;
    }

    // 从后向前遍历数组，倒序输出整个变化序列
    for (int i = idx - 1; i >= 0; i--) {
        std::cout << result_ary[i] << " ";
    }
    return 0;
}
