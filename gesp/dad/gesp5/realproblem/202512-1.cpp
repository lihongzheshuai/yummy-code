#include <algorithm>
#include <iostream>
#include <vector>

/**
 * GESP 2025年12月 五级编程题 T1: 数的移动
 *
 * 题目描述：
 * 给定 N 个整数的数组，每个数恰好出现 2 次。
 * 目标：将数组调整为 "相同数字相邻排列" 的形式 (如 [2,2,5,5])。
 * 操作：每次可以移动任意一个数字到任意位置，花费为其数值。
 * 限制：单次移动花费不超过 X。
 * 求：满足条件的最小 X。
 *
 * 算法思路：
 * 1. 这是一个 "二分答案" 的问题。
 *    - 如果阈值为 X，意味着所有数值 <= X 的元素都可以自由移动（视为 "消失" 或
 * "百搭"）。
 *    - 所有数值 > X 的元素位置相对固定，不可移动。
 * 2. 判定函数 check(mid)：
 *    - 提取原数组中所有大于 mid 的元素，组成子序列。
 *    - 检查该子序列是否满足 "相同数字相邻" 的要求。
 *      即：子序列第 0,1 项相等，第 2,3 项相等，以此类推。
 *    - 如果满足，说明 X = mid 可行（尝试更小）；否则不可行（需要更大）。
 * 3. 二分范围：[0, 10^9]。
 *
 * 复杂度：
 * - check 函数：O(N)
 * - 二分次数：log(10^9) ≈ 30 次
 * - 总复杂度：O(N log(10^9))，满足时间限制。
 */

using namespace std;

// 原数组
int n;
vector<int> a;

// 检查阈值 x 是否可行
bool check(int x) {
    vector<int> fixed_nums;
    // 筛选出不能移动的元素
    for (int val : a) {
        if (val > x) {
            fixed_nums.push_back(val);
        }
    }

    // 检查固定元素的相对顺序是否合法
    // 合法条件：成对出现且相邻
    if (fixed_nums.size() % 2 != 0)
        return false;  // 理论上不会发生，因为每个数出现2次，只要x确定，留下的必定是偶数个(除非同一个数的两个副本一个>x一个<=x，但这不可能)

    for (size_t i = 0; i < fixed_nums.size(); i += 2) {
        if (fixed_nums[i] != fixed_nums[i + 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    // 优化输入输出
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> n)) return 0;

    a.resize(n);
    int max_val = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        max_val = max(max_val, a[i]);
    }

    // 二分答案
    // 范围：最小可能花费 0，最大可能花费 max_val
    int l = 0, r = max_val;
    int ans = max_val;

    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (check(mid)) {
            ans = mid;
            r = mid - 1;  // 尝试更小的花费
        } else {
            l = mid + 1;  // 需要更大的花费才能移走阻碍元素
        }
    }

    cout << ans << endl;

    return 0;
}
