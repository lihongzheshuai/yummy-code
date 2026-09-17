/**
 * 题目: 【GESP】C++四级真题 luogu-B4006 [GESP202406 四级] 宝箱
 * 题号: B4006
 * 归属: GESP4级 (202406认证真题)
 * 解法: 解法 1 / 共 2 种解法
 * 博客: https://www.coderli.com/gesp-4-luogu-b4006/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <algorithm>
#include <iostream>

// 存储宝箱价值的数组
int val_arys[1005];
// 存储前缀和的数组
int pre_sum[1005];
int main() {
    // 读入宝箱数量n和最大价值差k
    int n, k;
    std::cin >> n >> k;
    // 读入每个宝箱的价值
    for (int i = 0; i < n; i++) {
        std::cin >> val_arys[i];
    }
    // 对宝箱价值进行排序，便于后续处理
    std::sort(val_arys, val_arys + n);
    // 计算第一个前缀和
    pre_sum[0] = val_arys[0];
    // 计算所有前缀和
    for (int i = 1; i < n; i++) {
        pre_sum[i] = pre_sum[i - 1] + val_arys[i];
    }
    // 记录最大总价值
    int max_sum = 0;
    // 枚举所有可能的价值范围
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            // 如果当前价值范围满足条件(最大值减最小值不超过k)
            if (val_arys[j] - val_arys[i] <= k) {
                // 使用前缀和计算当前范围内的总价值并更新最大值
                max_sum =
                    std::max(max_sum, pre_sum[j] - pre_sum[i] + val_arys[i]);
            } else {
                // 由于数组已排序，如果当前j位置与i位置的差值超过k
                // 后续的差值一定更大，可以直接跳出内层循环
                break;
            }
        }
    }
    // 输出结果
    std::cout << max_sum;
    return 0;
}
