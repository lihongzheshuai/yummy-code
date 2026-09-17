/**
 * 题目: 【GESP】luogu-P1873 [COCI 2011/2012 /#5] EKO / 砍树
 * 题号: P1873
 * 归属: GESP5级
 * 博客: https://www.coderli.com/luogu-p1873-eko/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

/**
 * Problem: luogu P1873 [COCI 2011/2012 #5] EKO / 砍树
 * Algorithm: 二分答案 (Binary Search on Answer)
 * Author: OneCoder
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 树木数量最大为 10^6
const int MAXN = 1000005;
int trees[MAXN];
int n;
long long m;

/**
 * @brief 判定函数：检查锯片设定在高度 mid 时，能否锯出至少 m 米木材
 * @param mid 猜测的锯片高度
 * @return true 表示能够得到至少 m 米木材；false 表示木材不足
 */
bool check(int mid) {
    long long sum = 0; // 必须使用 long long 累加，防止溢出
    for (int i = 0; i < n; i++) {
        if (trees[i] > mid) {
            sum += (trees[i] - mid);
            // 贪心剪枝：一旦满足所需木材量，立刻提前返回，提高常数效率
            if (sum >= m) {
                return true;
            }
        }
    }
    return sum >= m;
}

int main() {
    // 针对百万级输入规模开启 IO 流加速
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    if (!(cin >> n >> m)) {
        return 0;
    }

    int max_val = 0;
    for (int i = 0; i < n; i++) {
        cin >> trees[i];
        if (trees[i] > max_val) {
            max_val = trees[i];
        }
    }

    // 二分区间：高度下界为 0，上界为最高树的高度
    int l = 0, r = max_val;
    int ans = 0;

    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (check(mid)) {
            ans = mid;     // 当前高度可行，记录最优解
            l = mid + 1;   // 贪心尝试更高的锯片高度
        } else {
            r = mid - 1;   // 木材不够，锯片过高，向左半区间收缩
        }
    }

    cout << ans << "\n";

    return 0;
}
