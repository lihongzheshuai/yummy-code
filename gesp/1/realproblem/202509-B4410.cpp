/**
 * 题目: 【GESP】C++一级真题 luogu-B4410 [GESP202509 一级] 金字塔
 * 题号: B4410
 * 归属: GESP1级 (202509认证真题)
 * 博客: https://www.coderli.com/gesp-1-luogu-b4410/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>

int main() {
    int n;              // 金字塔的层数
    std::cin >> n;      // 读取用户输入的层数n

    int count = 0;      // 初始化总石块数为0

    // 从第n层循环到第1层，计算每层的石块数i*i，并累加到count中
    for (int i = n; i > 0; i--) {
        count += i * i; // 每层石块数为 i×i
    }

    std::cout << count << std::endl; // 输出总共需要的石块数量
    return 0;
}
