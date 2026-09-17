/**
 * 题目: 【GESP/CSP练习】GESP四级 / CSP-J 题解：luogu-P1028 [NOIP2001 普及组] 数的计算
 * 题号: P1028
 * 归属: GESP4级
 * 博客: https://www.coderli.com/gesp-4-luogu-p1028-number-calculation/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

/**
 * Problem: luogu-P1028 [NOIP2001 普及组] 数的计算
 * Algorithm: 基础递推 (Dynamic Programming / Recurrence)
 * Standard: C++11 (CCF GESP 官方大纲规范)
 * Author: OneCoder
 */

#include <iostream>

using namespace std;

// 数据规模保证 1 <= n <= 1000
// f[i] 表示以正整数 i 为起点的所有合法数列总数
// 经推导 f(1000) = 1981471878，极接近 32 位有符号整型上限 (2147483647)
// 在全局数据区开辟静态数组，杜绝局部变长数组 (VLA)，使用 long long 确保安全防溢出
const int MAXN = 1005;
long long f[MAXN];

int main() {
    int n;
    // 直接读入目标正整数 n
    cin >> n;

    // 自底向上递推计算每一个子问题的解 (1 到 n)
    for (int i = 1; i <= n; ++i) {
        // 每个数本身作为一个单元素数列 [i]，即为 1 种合法方案
        f[i] = 1;

        // 在 i 后面可以追加的正整数 j 必须满足 1 <= j <= i / 2
        // 追加 j 之后，后续所有以 j 为开头的合法数列均可接在其后，故累加 f[j]
        for (int j = 1; j <= i / 2; ++j) {
            f[i] += f[j];
        }
    }

    // 输出以 n 开头的合法数列总数量
    cout << f[n] << endl;

    return 0;
}
