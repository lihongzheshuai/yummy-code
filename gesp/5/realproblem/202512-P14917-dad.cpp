#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

int a[100005];
int N;

// 检查函数：判断当保留大于 x 的元素时，是否满足“相邻元素两两相等”的条件（比如 2
// 2 5 5）
bool check(int x) {
    // 定义一个向量 fixed，用于存储所有大于阈值 x 的元素
    std::vector<int> fixed;
    for (int i = 1; i <= N; i++) {
        // 遍历原数组，筛选出大于 x 的数
        if (a[i] > x) {
            fixed.push_back(a[i]);
        }
    }

    // 遍历筛选后的数组，每次步进 2，检查相邻两个元素是否相等
    // 根据题目数据，fixed.size() 一定是偶数，所以不会越界
    for (int i = 0; i < fixed.size(); i += 2) {
        if (fixed[i] != fixed[i + 1]) {
            return false;  // 如果这一对不相等，说明不能完美配对，返回 false
        }
    }
    return true;
}
int main() {
    std::cin >> N;
    int max = INT_MIN;
    int min = INT_MAX;
    for (int i = 1; i <= N; i++) {
        std::cin >> a[i];
        max = std::max(max, a[i]);
        min = std::min(min, a[i]);
    }

    // 二分查找
    // 目标：寻找满足 check(x) == true 的最小 x
    // 也就是找到一个最小的阈值，使得消除 <= 阈值的数后，剩下的数能组成对子。
    int l = min;
    int r = max;
    while (l < r) {
        int mid = l + (r - l) / 2;  // 防止 (l+r) 溢出，且向下取整
        if (check(mid)) {
            // 如果 mid 满足条件，尝试更小的 x，看能不能更小
            // 答案可能是 mid，也可能在左边
            r = mid;
        } else {
            // 如果 mid 不满足，说明阈值太小了，消除的数不够多（或者消除的不对）
            // 答案一定在 mid 右边，mid 本身肯定不行
            l = mid + 1;
        }
    }

    std::cout << l << '\n';
    return 0;
}