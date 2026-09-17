/**
 * 题目: 【GESP/CSP】编程武器库-5, 二分查找标准库(lower_bound/upper_bound)
 * 题号: 
 * 归属: CSP-J
 * 解法: 解法 4 / 共 4 种解法
 * 博客: https://www.coderli.com/gesp-arsenal-5-lower-upper-bound/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> nums = {1, 3, 5, 7, 9};

    // 1. 传统繁琐写法
    // std::vector<int>::iterator 是完整类型名
    std::vector<int>::iterator it1 = std::lower_bound(nums.begin(), nums.end(), 5);
    std::cout << "Index (传统): " << it1 - nums.begin() << std::endl;

    // 2. auto 现代写法（强烈推荐）
    // 编译器会自动推导出 it2 也是 std::vector<int>::iterator 类型
    auto it2 = std::lower_bound(nums.begin(), nums.end(), 5);
    std::cout << "Index (auto): " << it2 - nums.begin() << std::endl;

    return 0;
}
