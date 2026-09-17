#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

// 检查函数：判断是否能将数列分为不超过 M 段，且每段和最大不超过 limit
bool check(int n, int m, const std::vector<int>& a, int limit) {
    int segments = 1;
    int current_sum = 0;

    for (int x : a) {
        if (current_sum + x > limit) {
            segments++;  // 开启新的一段
            current_sum = x;
        } else {
            current_sum += x;
        }
    }

    return segments <= m;
}

int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> a(N);
    int sum = 0;
    int max_val = 0;

    for (int i = 0; i < N; i++) {
        std::cin >> a[i];
        max_val = std::max(max_val, a[i]);
        sum += a[i];
    }

    // 二分之 左边界 L = max_val, 右边界 R = sum
    int l = max_val, r = sum;
    int ans = sum;

    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (check(N, M, a, mid)) {
            ans = mid;
            r = mid - 1;  // 尝试更小的值
        } else {
            l = mid + 1;  // 值太小，需要增大
        }
    }

    std::cout << ans << std::endl;
    return 0;
}
