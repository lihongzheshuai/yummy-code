/**
 * 题目: 【NOIP】1997真题解析 luogu-P2241 统计方形（数据加强版） | GESP三、四级以上可练习
 * 题号: P2241
 * 归属: GESP4级
 * 解法: 解法 3 / 共 3 种解法
 * 博客: https://www.coderli.com/noi-p-1997-luogu-p2241/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, m;
    cin >> n >> m;

    // 总矩形数
    long long total_rectangles = (n * (n + 1) / 2) * (m * (m + 1) / 2);

    // 正方形总数公式展开计算
    long long K = min(n, m);
    long long A = n + 1;
    long long B = m + 1;

    // sum_1 = sum(k, 1..K) = K*(K+1)/2
    // sum_2 = sum(k^2, 1..K) = K*(K+1)*(2*K+1)/6
    long long sum_1 = K * (K + 1) / 2;
    long long sum_2 = K * (K + 1) * (2 * K + 1) / 6;

    long long squares = K * A * B - (A + B) * sum_1 + sum_2;
    long long pure_rectangles = total_rectangles - squares;

    cout << squares << " " << pure_rectangles << "\n";

    return 0;
}
