/**
 * 题目: 【NOIP】1997真题解析 luogu-P2241 统计方形（数据加强版） | GESP三、四级以上可练习
 * 题号: P2241
 * 归属: GESP4级
 * 解法: 解法 2 / 共 3 种解法
 * 博客: https://www.coderli.com/noi-p-1997-luogu-p2241/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, m;
    cin >> n >> m;

    long long squares = 0;         // 正方形数量
    long long pure_rectangles = 0; // 不含正方形的长方形数量

    // 枚举矩形的长 i 和宽 j
    for (long long i = 1; i <= n; ++i) {
        for (long long j = 1; j <= m; ++j) {
            long long count = (n - i + 1) * (m - j + 1);
            if (i == j) {
                squares += count;
            } else {
                pure_rectangles += count;
            }
        }
    }

    cout << squares << " " << pure_rectangles << "\n";

    return 0;
}
