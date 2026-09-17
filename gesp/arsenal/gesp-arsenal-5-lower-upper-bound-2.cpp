/**
 * 题目: 【GESP/CSP】编程武器库-5, 二分查找标准库(lower_bound/upper_bound)
 * 题号: 
 * 归属: CSP-J
 * 解法: 解法 2 / 共 4 种解法
 * 博客: https://www.coderli.com/gesp-arsenal-5-lower-upper-bound/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <algorithm> // 必须包含 lower_bound 和 upper_bound

int main() {
    // 准备有序数组
    int a[] = {10, 20, 20, 30, 40, 50};
    int n = 6;

    std::cout << "数组内容: {10, 20, 20, 30, 40, 50}" << std::endl << std::endl;

    // --- 场景 1: 查找存在的元素 (20) ---
    std::cout << "=== 场景 1: 查找 20 ===" << std::endl;
    // 1. 使用 int* 接收返回值（迭代器/指针）
    // 注意：如果是 vector，则使用 std::vector<int>::iterator 或 auto
    int* ptr_lb_20 = std::lower_bound(a, a + n, 20); // 返回指向第一个 >= 20 的元素的指针
    int* ptr_ub_20 = std::upper_bound(a, a + n, 20); // 返回指向第一个 > 20 的元素的指针

    // 2. 将指针转换为下标 (通过减去数组首地址 a)
    int lb_20 = ptr_lb_20 - a;
    int ub_20 = ptr_ub_20 - a;

    std::cout << "lower_bound(20) 下标: " << lb_20 << " (对应值: " << *ptr_lb_20 << ")" << std::endl; // 输出: 1 (值为 20)
    std::cout << "upper_bound(20) 下标: " << ub_20 << " (对应值: " << *ptr_ub_20 << ")" << std::endl; // 输出: 3 (值为 30)

    // --- 场景 2: 查找不存在的元素 (25) ---
    std::cout << "\n=== 场景 2: 查找 25 ===" << std::endl;
    int* ptr_lb_25 = std::lower_bound(a, a + n, 25);
    int* ptr_ub_25 = std::upper_bound(a, a + n, 25);

    int lb_25 = ptr_lb_25 - a;
    int ub_25 = ptr_ub_25 - a;

    std::cout << "lower_bound(25) 下标: " << lb_25 << " (对应值: " << *ptr_lb_25 << ")" << std::endl; // 输出: 3 (值为 30)
    std::cout << "upper_bound(25) 下标: " << ub_25 << " (对应值: " << *ptr_ub_25 << ")" << std::endl; // 输出: 3 (值为 30)

    // --- 场景 3: 查找超大元素 (100) ---
    std::cout << "\n=== 场景 3: 查找 100 ===" << std::endl;
    int* ptr_lb_100 = std::lower_bound(a, a + n, 100);
    int* ptr_ub_100 = std::upper_bound(a, a + n, 100);

    // 判断是否越界 (即没找到)
    if (ptr_lb_100 == a + n) {
        std::cout << "lower_bound(100) 返回 a + n，表示未找到 (越界)" << std::endl;
    }
    if (ptr_ub_100 == a + n) {
        std::cout << "upper_bound(100) 返回 a + n，表示未找到 (越界)" << std::endl;
    }

    // --- 场景 4: 查找超小元素 (5) ---
    std::cout << "\n=== 场景 4: 查找 5 ===" << std::endl;
    int* ptr_lb_5 = std::lower_bound(a, a + n, 5);
    int* ptr_ub_5 = std::upper_bound(a, a + n, 5);

    std::cout << "lower_bound(5) 下标: " << ptr_lb_5 - a << " (对应值: " << *ptr_lb_5 << ")" << std::endl; // 输出: 0 (值为 10)
    std::cout << "upper_bound(5) 下标: " << ptr_ub_5 - a << " (对应值: " << *ptr_ub_5 << ")" << std::endl; // 输出: 0 (值为 10)

    return 0;
}
