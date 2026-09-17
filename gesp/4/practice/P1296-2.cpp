/**
 * 题目: 【GESP】C++四级练习 luogu-P1296 奶牛的耳语
 * 题号: P1296
 * 归属: GESP4级
 * 解法: 解法 2 / 共 2 种解法
 * 博客: https://www.coderli.com/gesp-4-luogu-p1296/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 开启 I/O 加速
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, d;
    cin >> n >> d;

    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }

    // 1. 坐标升序排序
    sort(p.begin(), p.end());

    // 2. 对每个元素二分查找最远合法右边界
    long long ans = 0; // 必须使用 long long

    for (int i = 0; i < n; ++i) {
        // 在 [i + 1, n) 范围内查找第一个 > p[i] + d 的位置
        auto it = upper_bound(p.begin() + i + 1, p.end(), p[i] + d);
        // 合法区间为 [p.begin() + i + 1, it)
        ans += (it - (p.begin() + i + 1));
    }

    cout << ans << "\n";

    return 0;
}
