/**
 * 题目: 【GESP】C++三级练习 luogu-P5727 【深基5.例3】冰雹猜想
 * 题号: P5727
 * 归属: GESP3级
 * 解法: 解法 2 / 共 2 种解法
 * 博客: https://www.coderli.com/gesp-3-luogu-p5727/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <vector>

// 定义一个整型向量ary，用于存储冰雹猜想的数列变化过程
std::vector<int> ary;
int main() {
    // 读取输入的数字个数
    int n;
    std::cin >> n;

    // 将第一个数字加入向量
    ary.push_back(n);

    // 根据规则生成数列直到得到1
    while (n != 1) {
        // 如果是偶数则除以2
        if (n % 2 == 0) {
            n /= 2;
        }
        // 如果是奇数则乘3加1
        else {
            n = n * 3 + 1;
        }
        // 将新生成的数字加入向量
        ary.push_back(n);
    }

    // 从后向前遍历向量，输出所有数字
    for (int i = ary.size() - 1; i >= 0; i--) {
        std::cout << ary[i] << " ";
    }
    return 0;
}
