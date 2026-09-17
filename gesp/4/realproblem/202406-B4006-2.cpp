/**
 * 题目: 【GESP】C++四级真题 luogu-B4006 [GESP202406 四级] 宝箱
 * 题号: B4006
 * 归属: GESP4级 (202406认证真题)
 * 解法: 解法 2 / 共 2 种解法
 * 博客: https://www.coderli.com/gesp-4-luogu-b4006/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <algorithm>
#include <iostream>

// 存储宝箱价值的数组
int val_arys[1005];
int main() {
    // 读入宝箱数量n和最大价值差k
    int n, k;
    std::cin >> n >> k;
    // 读入每个宝箱的价值
    for (int i = 0; i < n; i++) {
        std::cin >> val_arys[i];
    }
    // 对宝箱价值进行排序，便于使用滑动窗口
    std::sort(val_arys, val_arys + n);
    // 记录最大总价值
    int max_sum = 0;
    // 滑动窗口左边界
    int left = 0;
    // 当前窗口内的价值总和
    int cur_sum = 0;
    // 滑动窗口右边界向右移动
    for (int right = 0; right < n; right++) {
        // 将右边界的宝箱加入当前总和
        cur_sum += val_arys[right];
        // 当窗口内最大值与最小值的差超过k时
        // 不断移动左边界直到满足条件
        // 由于数组已排序，right位置的值一定是当前窗口最大值
        // left位置的值一定是当前窗口最小值
        while(val_arys[right] - val_arys[left] > k) {
            // 移除窗口最左边的值，需要从当前和中减去
            cur_sum -= val_arys[left];
            // 左边界右移一位，缩小窗口范围
            // 由于数组有序，新的left位置值一定大于之前的值
            // 这样可以逐步减小最大值和最小值的差，直到满足条件
            left++;
        }
        // 更新最大总价值
        max_sum = std::max(max_sum, cur_sum);
    }

    // 输出结果
    std::cout << max_sum;
    return 0;
}
