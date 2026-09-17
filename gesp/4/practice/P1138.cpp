/**
 * 题目: 【GESP】C++四级练习 luogu-P1138 第 k 小整数
 * 题号: P1138
 * 归属: GESP4级
 * 博客: https://www.coderli.com/gesp-4-luogu-p1138/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <algorithm>
#include <iostream>

int main() {
    int n, k;
    std::cin >> n >> k;

    // 读入 n 个正整数
    int a[10001];
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    // 从小到大排序
    std::sort(a, a + n);

    // 排序后第一个元素就是第 1 小的整数
    int count = 1;

    // 如果 k 为 1，直接输出排序后的第一个元素
    if (count == k) {
        std::cout << a[0] << std::endl;
        return 0;
    }

    // 从第二个元素开始遍历，遇到不同的值则计数加一
    for (int i = 1; i < n; i++) {
        if (a[i] != a[i - 1]) {
            count++;
            if (count == k) {
                std::cout << a[i] << std::endl;
                return 0;
            }
        }
    }

    // 遍历结束仍未找到第 k 小的整数，输出无解
    std::cout << "NO RESULT" << std::endl;
    return 0;
}
