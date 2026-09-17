/**
 * 题目: 【GESP】C++五级练习 luogu-P1678 烦恼的高考志愿
 * 题号: P1678
 * 归属: GESP5级
 * 解法: 解法 2 / 共 2 种解法
 * 博客: https://www.coderli.com/gesp-5-luogu-p1678/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <algorithm> // 包含 std::sort
#include <cmath>     // 包含 std::abs
#include <iostream>  // 包含 std::cin 与 std::cout
#include <vector>    // 包含 std::vector

using namespace std;

/**
 * @brief 手写二分查找函数（等价于 std::lower_bound）
 * 
 * @param a 已排好序的升序数组
 * @param target 目标查找值（学生的估分 b）
 * @return int 第一个大于等于 target 的元素下标；若不存在则返回 a.size()
 */
int my_lower_bound(const vector<int>& a, int target) {
    int left = 0;
    int right = a.size() - 1;
    int ans = a.size(); // 初始值设为 a.size()，表示若所有元素都比 target 小时的默认返回值

    // 循环条件：左边界不超过右边界
    while (left <= right) {
        // 计算中间位置，采用 left + (right - left) / 2 可以防止 (left + right) 直接相加导致的数值溢出
        int mid = left + (right - left) / 2;

        if (a[mid] >= target) {
            ans = mid;       // 记录当前满足 >= target 的候选位置
            right = mid - 1; // 尝试在更左侧的区间寻找是否还有更靠前的合法位置
        } else {
            left = mid + 1;  // 当前值 a[mid] 小于 target，说明目标位置一定在 mid 右侧
        }
    }
    return ans; // 返回最终找到的第一个 >= target 的元素下标
}

int main() {
    // 快速输入输出优化
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n;
    if (!(cin >> m >> n)) return 0;

    // 读入 m 所学校录取线
    vector<int> a(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }

    // 1. 对学校录取线进行升序排序
    sort(a.begin(), a.end());

    // 2. 初始化总不满意度，必须为 long long 类型（防止累加溢出）
    long long total_dissatisfaction = 0;

    // 3. 处理每个学生的估分
    for (int i = 0; i < n; i++) {
        int b;
        cin >> b;

        // 使用手写的二分查找算法定位第一个大于等于 b 的学校下标 pos
        int pos = my_lower_bound(a, b);

        if (pos == 0) {
            // 下标为 0：估分低过所有学校，取录取线最低的学校 a[0]
            total_dissatisfaction += abs(a[0] - b);
        } else if (pos == m) {
            // 下标为 m：估分高过所有学校，取录取线最高的学校 a[m - 1]
            total_dissatisfaction += abs(a[m - 1] - b);
        } else {
            // 下标在 (0, m) 范围内：比较左侧 a[pos-1] 和右侧 a[pos]，累加较小绝对差
            int diff_right = abs(a[pos] - b);
            int diff_left = abs(a[pos - 1] - b);
            total_dissatisfaction += min(diff_right, diff_left);
        }
    }

    // 4. 输出答案
    cout << total_dissatisfaction << "\n";

    return 0;
}
