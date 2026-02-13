#include <algorithm>
#include <iostream>
#include <vector>

// P2249 【深基13.例1】查找 - STL版本实现
// 使用 std::lower_bound 快速查找第一个大于等于目标值的元素位置

int nums[1000005];

int main() {
    // 优化输入输出效率
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    if (!(std::cin >> n >> m)) return 0;

    for (int i = 1; i <= n; i++) {
        std::cin >> nums[i];
    }

    while (m--) {
        int q;
        std::cin >> q;

        // std::lower_bound 返回指向第一个 >= q 的元素的指针（或迭代器）
        // 范围是 [nums + 1, nums + n + 1)
        int* p = std::lower_bound(nums + 1, nums + n + 1, q);

        // 检查是否找到：
        // 1. p != nums + n + 1: 确保没有越界（即数组中存在 >= q 的数）
        // 2. *p == q: 确保找到的数确实是 q（因为 lower_bound 也可能返回大于 q
        // 的数）
        if (p != nums + n + 1 && *p == q) {
            // 计算下标：指针相减
            std::cout << (p - nums) << " ";
        } else {
            // 没找到或者找到的是大于 q 的数
            std::cout << -1 << " ";
        }
    }
    std::cout << "\n";

    return 0;
}
