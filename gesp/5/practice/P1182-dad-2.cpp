/**
 * P1182 数列分段 Section II
 *
 * 题目要求：
 * 将一个长度为 N 的数列分成 M 段，要求每段连续。
 * 目标是让“每段和的最大值”最小。
 *
 * 思路分析：
 * 这是一个典型的“二分答案”（Binary Search on Answer）问题。
 * 我们二分枚举“每段和的最大值”这一可能得答案（设为 x）。
 * 然后检查：如果每段和最大不超过 x，最少需要分成几段？
 * - 如果最少分成的段数 <= M，说明 x 还可以更小（或者 x 正好），尝试往左搜。
 * - 如果最少分成的段数 > M，说明 x 太小了，塞不下，需要往右搜。
 */

#include <climits>
#include <cmath>
#include <iostream>

// 使用 long long (ll) 是为了防止和溢出。
// 虽然 N <= 10^5, A_i <= 10^8，但总和可能达到 10^13，超过 int (2*10^9) 范围。
typedef long long ll;
const int MAXN = 100005;
ll a[MAXN];

/**
 * 检查函数 check(limit)
 * 功能：判断当每段和的最大值不超过 limit 时，最少需要分多少段。
 *
 * 贪心策略：
 * 尽可能把更多的数字塞进当前这一段，直到塞不下（和超过 limit）为止，
 * 然后开启新的一段。这样得到的段数是最少的。
 */
bool check(int n, int m, ll limit) {
    int seg = 1;     // 当前是第几段（初始为第1段）
    ll cur_sum = 0;  // 当前这一段的累加和
    for (int i = 1; i <= n; i++) {
        // 如果加上当前数字 a[i] 会超过限制 limit
        if (cur_sum + a[i] > limit) {
            seg++;           // 必须开启新的一段
            cur_sum = a[i];  // 新的一段从 a[i] 开始
        } else {
            cur_sum += a[i];  // 否则加到当前段里
        }
    }
    // 如果最少需要的段数 seg <= m，说明 limit 是可行的（甚至可能偏大），返回
    // true
    return seg <= m;
}

int main() {
    int N, M;
    std::cin >> N >> M;
    ll sum = 0;
    ll l = 0;  // 二分下界：答案至少是数列中的最大值（因为一段至少包含一个数）
    for (int i = 1; i <= N; i++) {
        std::cin >> a[i];
        sum += a[i];
        l = std::max(l, a[i]);
    }

    // 二分上界：答案至多是所有数的和（即只分成 1 段）
    ll r = sum;

    // 二分查找
    while (l <= r) {
        ll mid = l + (r - l) / 2;
        if (check(N, M, mid)) {
            // 如果 limit = mid 可行（分的段数 <= M），说明答案可能是 mid
            // 或者更小
            r = mid - 1;
        } else {
            // 如果不可行（分的段数 > M），说明 limit 太小了，需要增大
            l = mid + 1;
        }
    }

    // 最终 l 指向的就是满足条件的最小值
    std::cout << l << '\n';
    return 0;
}