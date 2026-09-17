/**
 * 题目: 【GESP】C++四级练习 luogu-P1296 奶牛的耳语
 * 题号: P1296
 * 归属: GESP4级
 * 解法: 解法 1 / 共 2 种解法
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

    // 2. 双指针扫描统计
    long long ans = 0; // 必须使用 long long 防止溢出
    int j = 0;

    for (int i = 0; i < n; ++i) {
        // 右指针向右滑动，直到超出距离 d 或到达边界
        while (j + 1 < n && p[j + 1] - p[i] <= d) {
            ++j;
        }
        // 与当前奶牛 i 配对的合法奶牛数为 j - i
        ans += (j - i);
    }

    cout << ans << "\n";

    return 0;
}
