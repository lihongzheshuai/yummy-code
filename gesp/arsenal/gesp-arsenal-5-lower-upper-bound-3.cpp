/**
 * 题目: 【GESP/CSP】编程武器库-5, 二分查找标准库(lower_bound/upper_bound)
 * 题号: 
 * 归属: CSP-J
 * 解法: 解法 3 / 共 4 种解法
 * 博客: https://www.coderli.com/gesp-arsenal-5-lower-upper-bound/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // 准备有序 vector
    std::vector<int> v = {10, 20, 30, 30, 30, 40, 50};

    std::cout << "Vector内容: {10, 20, 30, 30, 30, 40, 50}" << std::endl << std::endl;

    // --- 查找 30 的范围 ---
    std::cout << "=== 查找 30 ===" << std::endl;

    // 1. 使用迭代器接收返回值
    // std::vector<int>::iterator 是完整类型名，太长了，通常用 auto 关键字自动推导
    std::vector<int>::iterator it_lb = std::lower_bound(v.begin(), v.end(), 30);
    auto it_ub = std::upper_bound(v.begin(), v.end(), 30); // 推荐用 auto

    // 2. 将迭代器转换为下标 (通过减去 v.begin())
    int idx_lb = it_lb - v.begin();
    int idx_ub = it_ub - v.begin();

    std::cout << "lower_bound(30) 下标: " << idx_lb << " (对应值: " << *it_lb << ")" << std::endl; // 输出: 2
    std::cout << "upper_bound(30) 下标: " << idx_ub << " (对应值: " << *it_ub << ")" << std::endl; // 输出: 5

    std::cout << "30 出现的次数: " << idx_ub - idx_lb << std::endl; // 输出: 3
    std::cout << "30 出现的下标范围: [" << idx_lb << ", " << idx_ub - 1 << "]" << std::endl;

    // --- 查找不存在的元素 35 ---
    std::cout << "\n=== 查找 35 ===" << std::endl;
    auto it_35 = std::lower_bound(v.begin(), v.end(), 35);

    // 判断是否越界 (即没找到)
    if (it_35 == v.end()) {
        std::cout << "没找到 35 (越界)" << std::endl;
    } else {
        std::cout << "35 应该插入的位置下标: " << it_35 - v.begin() << std::endl; // 输出: 5 (40的位置)
    }

    return 0;
}
