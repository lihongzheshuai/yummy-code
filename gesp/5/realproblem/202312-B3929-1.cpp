/**
 * 题目: 【GESP】C++五级真题（埃氏筛思想考点） luogu-B3929 [GESP202312 五级] 小杨的幸运数
 * 题号: B3929
 * 归属: GESP5级 (202312认证真题)
 * 解法: 解法 1 / 共 2 种解法
 * 博客: https://www.coderli.com/gesp-5-luogu-b3929/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <cmath>
#include <iostream>

int lucky_nums[1002100];

int main() {
    int a, N;
    std::cin >> a >> N;  // 读入起始完全平方数下界 a 与询问次数 N

    // 埃氏筛思想：标记所有超级幸运数（≥a 的完全平方数）及其倍数
    for (int i = std::ceil(std::sqrt(a)); i <= 1001; i++) {
        int square_num = i * i;          // 当前超级幸运数
        lucky_nums[square_num] = 1;      // 标记自己
        for (int j = 2; j * square_num <= 1002000; j++) {
            lucky_nums[j * square_num] = 1;  // 标记其所有倍数
        }
    }

    // 处理 N 次询问
    for (int i = 0; i < N; i++) {
        int x;
        std::cin >> x;
        if (lucky_nums[x]) {             // 若 x 已是幸运数
            std::cout << "lucky" << std::endl;
        } else {
            int max_n = std::max(x, a);  // 从 max(x,a) 开始往后找第一个幸运数
            for (int j = max_n; j <= 1002100; j++) {
                if (lucky_nums[j]) {
                    std::cout << j << std::endl;  // 输出幸运化结果
                    break;
                }
            }
        }
    }

    return 0;
}
