/*
 * 题目名称：奖品兑换
 * 题目来源：GESP 202506 五级
 * 题目编号：P13013
 *
 * 解题思路：
 * 这是一个最大化问题。我们需要求出最多能兑换多少份奖品。
 * 设兑换了 x 份第一种奖品（a张课堂券 + b张作业券），y 份第二种奖品（b张课堂券 +
 * a张作业券）。 我们的目标是最大化 k = x + y。
 *
 * 约束条件为：
 * 1. a * x + b * y <= n
 * 2. b * x + a * y <= m
 * 3. x >= 0, y >= 0
 *
 * 我们可以二分答案 k (总奖品数)。
 * 对于一个固定的 k，我们需要判断是否存在非负整数 x, y 满足 x + y = k
 * 且满足上述不等式。 将 y = k - x 代入不等式：
 * 1. a * x + b * (k - x) <= n  =>  (a - b) * x + b * k <= n
 * 2. b * x + a * (k - x) <= m  =>  (b - a) * x + a * k <= m
 *
 * 我们不妨设 a <= b (如果 a > b，可以交换 a,
 * b，这不影响结果，因为两种奖品是对称的)。 当 a <= b 时： 不等式 1 化为：(a -
 * b) * x <= n - b * k。因为 a - b <= 0，两边除以负数变号（或者移项）： (b - a)
 * * x >= b * k - n   =>   x >= (b * k - n) / (b - a) 不等式 2 化为：(b - a) * x
 * <= m - a * k   =>   x <= (m - a * k) / (b - a)
 *
 * 此外，还需要满足 0 <= x <= k。
 * 所以，对于固定的 k，x 的取值范围是：
 * lower_bound = max(0, ceil((b * k - n) / (b - a)))
 * upper_bound = min(k, floor((m - a * k) / (b - a)))
 *
 * 如果 lower_bound <= upper_bound，则说明存在合法的 x，即 k 是可行的。
 *
 * 特殊情况：如果 a = b，则不等式变为 a * k <= n 和 a * k <= m，直接判断 k <=
 * min(n, m) / a 即可。
 *
 * 时间复杂度：O(log(n + m))，足以通过 400ms 的时限。
 */

#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

typedef long long ll;

ll n, m, a, b;

// 检查是否能兑换 k 份奖品
bool check(ll k) {
    // 如果 a == b，直接判断
    if (a == b) {
        // 需要 a*k <= n 且 a*k <= m
        // 也就是 k <= n/a 且 k <= m/a
        // 避免溢出，先判断乘法
        if (n / a < k) return false;
        if (m / a < k) return false;
        return true;
    }

    // 此时假设 a < b (在 main 函数中保证)
    // 不等式 1: x >= (b*k - n) / (b - a)
    // 不等式 2: x <= (m - a*k) / (b - a)

    ll diff = b - a;

    // 计算下界 L
    // x >= (b*k - n) / diff
    // 如果 b*k - n <= 0，则下界为负数，由于 x >= 0，所以实际下界为 0
    // 如果 b*k - n > 0，则需要向上取整。 (val + diff - 1) / diff
    ll min_x = 0;
    if (b * k > n) {
        min_x = (b * k - n + diff - 1) / diff;
    }

    // 计算上界 R
    // x <= (m - a*k) / diff
    // 如果 m - a*k < 0，说明即使 x 取最小值也不满足，无解
    if (m < a * k) return false;
    ll max_x = (m - a * k) / diff;

    // 还要满足 x <= k
    max_x = min(max_x, k);

    return min_x <= max_x;
}

int main() {
    // 优化 I/O
    ios::sync_with_stdio(false);
    cin.tie(0);

    if (!(cin >> n >> m >> a >> b)) return 0;

    // 保证 a <= b，方便处理
    if (a > b) swap(a, b);

    // 二分答案
    // 下界 0，上界 (n + m) / (a + b) 或者简单点 2e9
    // 理论最大值：假设 a=1, b=1, n=1e9, m=1e9 => 2e9
    ll left = 0, right = 2000000000LL;
    // 也可以更精确一点： right = (n + m) / (a + b) + 1;
    if (a + b > 0) {
        right = (n + m) / (a + b) + 2;
    }

    ll ans = 0;
    while (left <= right) {
        ll mid = left + (right - left) / 2;
        if (check(mid)) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << ans << endl;

    return 0;
}
