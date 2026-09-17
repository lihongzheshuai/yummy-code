/**
 * 题目: 【GESP】C++五级真题（贪心和剪枝思想） luogu-B3930 [GESP202312 五级] 烹饪问题
 * 题号: B3930
 * 归属: GESP5级 (202312认证真题)
 * 解法: 解法 1 / 共 3 种解法
 * 博客: https://www.coderli.com/gesp-5-luogu-b3930/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <cmath>

int a[1000005];  // 存储每种食材的美味度，数组大小开到 1e6+5，防止越界
int main() {
    int N;
    std::cin >> N;                       // 读入食材数量 N
    for (int i = 0; i < N; i++) {
        std::cin >> a[i];                // 依次读入每种食材的美味度
    }
    int max_a = -1;                      // 初始化最大契合度为 -1（所有 a_i 均非负）
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            max_a = std::max(max_a, a[i] & a[j]);  // 计算两两按位与，更新最大值
        }
    }
    std::cout << max_a << std::endl;     // 输出最高契合度
    return 0;                            // 程序结束
}
