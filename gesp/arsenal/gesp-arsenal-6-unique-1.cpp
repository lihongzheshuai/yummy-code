/**
 * 题目: 【GESP/CSP】编程武器库-6, 去重算法(unique)
 * 题号: 
 * 归属: CSP-J
 * 解法: 解法 1 / 共 2 种解法
 * 博客: https://www.coderli.com/gesp-arsenal-6-unique/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <algorithm>

int main() {
    int a[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    int n = sizeof(a) / sizeof(a[0]);

    // 步骤1：先排序，相同的元素挨在一起，这是全局去重的必要前提
    std::sort(a, a + n);
    // 排序后为: 1, 1, 2, 3, 3, 4, 5, 5, 6, 9

    // 步骤2：使用 unique 覆盖相邻的重复元素
    // k 等同于非重复元素的个数
    int k = std::unique(a, a + n) - a;

    std::cout << "去重后的元素个数: " << k << std::endl;
    std::cout << "去重后的数组内容: ";
    // 注意：这里的循环上限变成了 k，摒弃了尾部的脏数据
    for (int i = 0; i < k; i++) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
