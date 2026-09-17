#include <iostream>
#include <cstdio>
#include <chrono>  // 用于时间测量

int main() {
    int iterations = 10000;

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