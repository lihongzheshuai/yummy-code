#include <algorithm>
#include <iostream>
#include <vector>

const int MAXN = 200005;
long long a[MAXN];

int main() {
    // 关闭同步，加速 IO
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    long long c;
    if (!(std::cin >> n >> c)) return 0;

    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    // 1. 排序，为双指针或二分查找做准备
    std::sort(a, a + n);

    long long ans = 0;
    int l = 0, r = 0;

    // 2. 遍历每一个数作为 B (a[i])
    for (int i = 0; i < n; i++) {
        long long target = a[i] + c;  // 我们要找的目标 A

        // 寻找第一个 >= target 的位置 (l)
        // 随着 a[i] 增大，target 也增大，l 只会向右移动，不需要回退
        while (l < n && a[l] < target) {
            l++;
        }

        // 寻找第一个 > target 的位置 (r)
        // 同样，r 也只会向右移动
        while (r < n && a[r] <= target) {
            r++;
        }

        // 区间 [l, r) 中的所有元素都等于 target
        if (l < n && a[l] == target) {
            ans += (r - l);
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
