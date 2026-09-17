#include <algorithm>
#include <iostream>

typedef long long ll;

// 全局数组存储每根原木的长度，大小需稍大于 10^5
int a[100005];

// check 函数：验证是否能切出 k 段长度为 mid 的木头
// mid: 当前尝试的小段木头长度
// n: 原木根数
// k: 目标段数
bool check(int mid, int n, int k) {
    ll cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt += a[i] / mid;
        if (cnt >= k) {
            return true;
        }
    }
    return false;
}

int main() {
    int n, k;
    std::cin >> n >> k;
    int r = 0;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        // 确定二分查找的上界：一小段的最长长度不可能超过最长的那根原木
        r = std::max(r, a[i]);
        sum += a[i];
    }

    if (sum < k) {
        std::cout << 0 << std::endl;
        return 0;
    }

    // 二分查找答案
    // 答案区间 [l, r] 初始化为 [1, 最长原木长度]
    int l = 1;
    int ans = 0;
    while (l <= r) {
        // 计算中间值，mid 即为当前尝试的长度
        int mid = l + (r - l) / 2;
        if (check(mid, n, k)) {
            // 如果 mid 长度可行，说明可能还有更优解（更长），向右半区间查找
            ans = mid;
            l = mid + 1;
        } else {
            // 如果 mid 长度不可行（切不够 k 段），说明 mid 太长，向左半区间查找
            r = mid - 1;
        }
    }

    std::cout << ans << std::endl;
    return 0;
}