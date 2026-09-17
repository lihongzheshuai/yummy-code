/**
 * 题目: 【NOIP】1997真题解析 luogu-P2241 统计方形（数据加强版） | GESP三、四级以上可练习
 * 题号: P2241
 * 归属: GESP4级
 * 解法: 解法 1 / 共 3 种解法
 * 博客: https://www.coderli.com/noi-p-1997-luogu-p2241/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    // 提高输入输出效率
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, m;
    if (!(cin >> n >> m)) {
        return 0;
    }

    // 1. 利用组合公式计算所有矩形（包含正方形）的总数
    long long total_rectangles = (n * (n + 1) / 2) * (m * (m + 1) / 2);

    // 2. 单层循环枚举正方形的边长 k
    long long squares = 0;
    long long limit = min(n, m);
    for (long long k = 1; k <= limit; ++k) {
        squares += (n - k + 1) * (m - k + 1);
    }

    // 3. 纯长方形数量 = 总矩形数 - 正方形数
    long long pure_rectangles = total_rectangles - squares;

    cout << squares << " " << pure_rectangles << "\n";

    return 0;
}
