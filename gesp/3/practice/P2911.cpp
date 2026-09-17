/**
 * 题目: 【GESP】C++三级练习 luogu-P2911 [USACO08OCT] Bovine Bones G
 * 题号: P2911
 * 归属: GESP3级
 * 博客: https://www.coderli.com/gesp-3-luogu-p2911/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>

// 用于存储每个骰子点数和出现的次数
int result[100] = {0};
int main () {
    // 三个骰子的面数
    int s1, s2, s3;
    // 从标准输入读取三个骰子的面数
    std::cin >> s1 >> s2 >> s3;

    // 三重循环遍历所有可能的骰子组合
    for (int i = 1; i <= s1; i++) {
        for (int j = 1; j <= s2; j++) {
            for (int k = 1; k <= s3;k++) {
                // 统计每个和出现的次数
                result[i + j + k]++;
            }
        }
    }

    // 记录最大出现次数
    int max = 0;
    // 记录最大出现次数对应的和
    int max_idx = 0;
    // 遍历所有可能的和，找出出现次数最多的最小和
    for (int i = 0; i <= s1 + s2 + s3; i++) {
        if (result[i] > max) {
            max = result[i];
            max_idx = i;
        }
    }
    // 输出结果
    std::cout << max_idx;
    return 0;
}
