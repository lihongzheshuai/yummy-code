/**
 * 题目: 【GESP/CSP】编程武器库-6, 去重算法(unique)
 * 题号: 
 * 归属: CSP-J
 * 解法: 解法 2 / 共 2 种解法
 * 博客: https://www.coderli.com/gesp-arsenal-6-unique/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> v = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};

    // 1. 从小到大排序
    std::sort(v.begin(), v.end());

    // 2. 将 unique 返回的指向脏数据的头部指针传给 vector 自身的 erase 函数：
    // 执行一键区间抹除，实现物理上的缩容！
    auto it = std::unique(v.begin(), v.end());
    v.erase(it, v.end());

    // 一步到位紧凑写法：
    // v.erase(std::unique(v.begin(), v.end()), v.end());

    std::cout << "彻底去重后的新长度: " << v.size() << std::endl;
    for (int num : v) {
        std::cout << num << " ";
    }
    return 0;
}
