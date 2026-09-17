/**
 * 题目: 【GESP】C++一级真题 luogu-B4495, [GESP202603 一级] 交朋友
 * 题号: B4495
 * 归属: GESP1级 (202603认证真题)
 * 博客: https://www.coderli.com/gesp-1-luogu-b4495/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>

int main() {
    // 存储 Alice 的身高
    int h1;
    std::cin >> h1;

    // 记录目前发现的最小身高差距，初始值设为一个足够大的数
    int min_diff = 1000;
    // 记录目前最符合条件的同学的身高
    int best_h = 0;

    // 循环 3 次，处理剩下的 3 个同学
    for (int i = 0; i < 3; i++) {
        int h;
        std::cin >> h;

        // 计算当前输入的同学身高 h 与 Alice 身高 h1 的差值的绝对值
        int diff;
        if (h > h1) {
            diff = h - h1;
        } else {
            diff = h1 - h;
        }

        // 如果发现更小的身高差，直接记录
        if (diff < min_diff) {
            min_diff = diff; // 更新最小差距记录
            best_h = h;      // 暂时敲定找这个同学交朋友
        }
        // 如果身高差和目前记录的最小身高差一样大，那么选择较矮的那一个
        else if (diff == min_diff) {
            if (h < best_h) {
                best_h = h;  // 发现了同样身高差，但身高更矮的同学
            }
        }
    }

    // 输出最终确定的人当朋友
    std::cout << best_h << std::endl;

    return 0;
}
