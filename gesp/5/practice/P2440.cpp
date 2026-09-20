/**
 * 题目: 【GESP/CSP练习】GESP五级 / CSP-J 题解：luogu-P2440 木材加工
 * 题号: P2440
 * 归属: GESP5级 / CSP-J
 * 博客: https://www.coderli.com/gesp-5-luogu-p2440-wood-cut/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <algorithm>

using namespace std;

// 数据规模：n <= 10^5, 原木长度 L_i <= 10^8
const int MAXN = 100005;
int a[MAXN];

// check 函数：检验是否能够切割出至少 k 段长度为 len 的小木头
// 单调性核心：len 越小，切出的小段越多；len 越大，切出的小段越少
bool check(int len, int n, long long k) {
    long long count = 0;
    for (int i = 0; i < n; ++i) {
        // 每根原木长度为 a[i]，最多可切出 a[i] / len 段长度为 len 的小木头
        count += a[i] / len;
        // 剪枝：一旦累计段数达到或超过目标 k，说明该长度可行，直接返回 true
        if (count >= k) {
            return true;
        }
    }
    return count >= k;
}

int main() {
    int n;
    long long k;
    cin >> n >> k;

    int max_len = 0;
    long long total_len = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] > max_len) {
            max_len = a[i];
        }
        total_len += a[i];
    }

    // 边界特判：若所有原木总长度累加仍小于目标段数 k，
    // 则即便每段长度取最小正整数 1cm，也无法切出 k 段，直接输出 0
    if (total_len < k) {
        cout << 0 << endl;
        return 0;
    }

    // 二分答案：小段长度 l 的取值范围为 [1, max_len]
    int left = 1;
    int right = max_len;
    int ans = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        // 判定当前长度 mid 是否满足要求
        if (check(mid, n, k)) {
            // 如果长度为 mid 可行，记录该可行解，并尝试寻找更长的小段（向右半区间搜索）
            ans = mid;
            left = mid + 1;
        } else {
            // 如果长度为 mid 无法切出 k 段，说明太长了，向左半区间压缩
            right = mid - 1;
        }
    }

    // 输出所能得到的小段木头的最大长度 l
    cout << ans << endl;

    return 0;
}
