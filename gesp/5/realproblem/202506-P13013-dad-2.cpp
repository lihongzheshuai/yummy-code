#include <cmath>
#include <iostream>

typedef long long ll;

ll n, m, a, b;

// 检查是否能兑换 k 份奖品
// 假设使用了 x 张第一种方案（a 张课堂券，b 张作业券）
// 那么使用了 k - x 张第二种方案（b 张课堂券，a 张作业券）
// 需满足：
// x * a + (k - x) * b <= n  => x * (a - b) <= n - k * b
// x * b + (k - x) * a <= m  => x * (b - a) <= m - k * a => x * (a - b) >= k * a
// - m 因为在 main 函数中保证了 a >= b，所以 a - b >= 0
bool check(ll k) {
    ll diff = a - b;
    ll l = 0;
    // 计算 x 的下界：x >= (k * a - m) / (a - b)
    if (a * k > m) {
        l = std::ceil((a * k - m) / (double)diff);
    }
    // 如果即使全部用第二种方案（消耗 b 张课堂券），课堂券也不够，直接返回 false
    if (b * k > n) {
        return false;
    }
    // 计算 x 的上界：x <= (n - k * b) / (a - b)
    ll r = (n - b * k) / diff;
    // x 不能超过总奖品数 k
    r = std::min(r, k);

    // 如果存在合法的 x (即区间 [l, r] 非空)，则说明可以兑换 k 份
    return l <= r;
}

int main() {
    std::cin >> n >> m >> a >> b;

    ll count = 0;

    // 特殊情况：如果两种方案消耗相同，直接看总资源能换多少
    // 实际上此时 a=b，只能换 min(n, m) / a 份
    if (a == b) {
        count = std::min(n, m) / a;
        std::cout << count;
        return 0;
    }

    // 保证 a >= b，方便 check 函数中的不等式处理（避免除以负数）
    if (a < b) {
        std::swap(a, b);
    }

    // 二分答案
    // 答案的范围在 0 到 max(n, m) 之间
    ll left = 0;
    ll right = std::max(n, m);
    ll ans = 0;
    while (left <= right) {
        ll mid = left + (right - left) / 2;
        if (check(mid)) {
            ans = mid;  // 如果能换 mid 份，尝试更多
            left = mid + 1;
        } else {
            right = mid - 1;  // 否则减少尝试数量
        }
    }

    std::cout << ans;

    return 0;
}