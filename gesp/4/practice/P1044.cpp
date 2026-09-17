/**
 * 题目: 【GESP/CSP练习】GESP四级 / CSP-J 题解：luogu-P1044 [NOIP2003 普及组] 栈
 * 题号: P1044
 * 归属: GESP4级 / CSP-J
 * 博客: https://www.coderli.com/gesp-4-luogu-p1044-stack-catalan/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>

using namespace std;

// 数据规模：保证 1 <= n <= 18
// h[i] 表示含有 i 个元素的操作数序列，经过合法的进栈、出栈操作后可能得到的出栈序列总数（即第 i 项卡特兰数）
// 当 n = 18 时，h[18] = 477638700，在 32 位整型范围内，但为防止乘法溢出及遵循规范统一采用 long long
const int MAXN = 25;
long long h[MAXN];

int main() {
    int n;
    // 直接读入操作数序列长度 n
    cin >> n;

    // 边界初始化：
    // 0 个元素（空状态）方案数为 1，1 个元素只有 1 种出栈可能
    // 注意：h[0] 必须初始化为 1，否则后续卷积乘积项将全部退化为 0
    h[0] = 1;
    h[1] = 1;

    // 自底向上递推计算卡特兰数 h[2] 到 h[n]
    // 状态转移方程：h[i] = sum_{j=0}^{i-1} (h[j] * h[i - 1 - j])
    for (int i = 2; i <= n; ++i) {
        h[i] = 0;
        for (int j = 0; j < i; ++j) {
            h[i] += h[j] * h[i - 1 - j];
        }
    }

    // 输出包含 n 个数时所有可能的出栈序列总数目
    cout << h[n] << endl;

    return 0;
}
