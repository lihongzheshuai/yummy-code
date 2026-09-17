/**
 * 题目: 【GESP】C++一级知识点研究，cout和printf性能差异分析
 * 题号: 
 * 归属: GESP1级
 * 解法: 解法 2 / 共 2 种解法
 * 博客: https://www.coderli.com/gesp-knowledge-cout-printf/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <cstdio>
#include <chrono>  // 用于时间测量

int main() {
    int iterations = 100000;

    // 测量 printf 的性能
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < iterations; ++i) {
        printf("%d\n", i);
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "printf: "
              << std::chrono::duration<double>(end - start).count()
              << " 秒" << std::endl;
    return 0;

    // 测量 cout 的性能
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < iterations; ++i) {
        std::cout << i << std::endl;
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "cout: "
              << std::chrono::duration<double>(end - start).count()
              << " 秒" << std::endl;

    // 测量 cout 的性能
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < iterations; ++i) {
        std::cout << i << "\n";
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "cout: "
              << std::chrono::duration<double>(end - start).count()
              << " 秒" << std::endl;
}
