#include <iostream>

/**
 * GESP 2025年12月 二级编程题 T2: 黄金格
 *
 * 题目核心：
 * 在 H 行 W 列的地图中，统计满足不等式 sqrt(r^2 + c^2) <= x + r - c
 * 的格子数量。
 *
 * 注意点：
 * 1. 坐标 r 和 c 的范围分别是 [1, H] 和 [1, W]。
 * 2. 为了避免 sqrt 带来的浮点数精度误差，我们可以将不等式两边平方进行比较。
 *    平方的前提是不等式右边 (x + r - c) 必须大于等于 0。
 *    因为左边是根号结果（非负），如果右边是负数，则不等式一定不成立。
 */

int main() {
    int h, w, x;
    // 输入 h, w, x 分别占三行
    std::cin >> h >> w >> x;

    int count = 0;
    // 双重循环遍历所有格子 (r, c)
    for (int r = 1; r <= h; r++) {
        for (int c = 1; c <= w; c++) {
            // 计算不等式右边的值
            long long rhs = (long long)x + r - c;

            // 只有当右边 rhs >= 0 时，平方后的比较才有效
            if (rhs >= 0) {
                // 左边平方：r^2 + c^2
                long long left_sq = (long long)r * r + (long long)c * c;
                // 右边平方：(x + r - c)^2
                long long right_sq = rhs * rhs;

                // 比较平方值
                if (left_sq <= right_sq) {
                    count++;
                }
            }
        }
    }

    // 输出满足条件的格子总数
    std::cout << count;

    return 0;
}