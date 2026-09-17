/**
 * 题目: 【GESP/CSP】编程武器库-5, 二分查找标准库(lower_bound/upper_bound)
 * 题号: 
 * 归属: CSP-J
 * 解法: 解法 1 / 共 4 种解法
 * 博客: https://www.coderli.com/gesp-arsenal-5-lower-upper-bound/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // --- 1. 数组示例 ---
    int a[] = {10, 20, 30, 40};
    // 查找 >= 30 的第一个元素
    int* p = std::lower_bound(a, a + 4, 30); // 返回指针

    std::cout << "数组找到的值: " << *p << std::endl;        // 解引用取值 -> 30
    std::cout << "数组下标: " << p - a << std::endl;         // 指针减法取下标 -> 2

    // --- 2. Vector 示例 ---
    std::vector<int> v = {10, 20, 30, 40};
    // 查找 >= 30 的第一个元素
    auto it = std::lower_bound(v.begin(), v.end(), 30); // 返回迭代器

    std::cout << "Vector找到的值: " << *it << std::endl;     // 解引用取值 -> 30
    std::cout << "Vector下标: " << it - v.begin() << std::endl; // 迭代器减法取下标 -> 2

    return 0;
}
