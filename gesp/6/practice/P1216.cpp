/**
 * 题目: 【GESP/CSP练习】GESP六级 / CSP-J 题解：luogu-P1216 [USACO1.5] 数字三角形
 * 题号: P1216
 * 归属: GESP六级 / CSP-J
 * 博客: https://www.coderli.com/gesp-6-luogu-p1216-triangle-dp/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <algorithm>

using namespace std;

// 最大行数 1000，预留边界安全裕量
const int MAXN = 1005;

// a[i][j] 存储原始数字金字塔的数值
int a[MAXN][MAXN];

// dp[i][j] 表示从坐标 (i, j) 出发走到金字塔底部的最大路径权值和
int dp[MAXN][MAXN];

int main() {
    // 读入数字金字塔的行数 r
    int r;
    cin >> r;

    // 读入金字塔的每一行数值
    // 第 i 行共有 i 个数字
    for (int i = 1; i <= r; ++i) {
        for (int j = 1; j <= i; ++j) {
            cin >> a[i][j];
        }
    }

    // 边界初始状态：金字塔最底层 (第 r 行) 向下走的最大和即为自身数值
    for (int j = 1; j <= r; ++j) {
        dp[r][j] = a[r][j];
    }

    // 自底向上逆推：从倒数第二行 (r - 1) 逐步递推至金字塔顶部 (第 1 行)
    for (int i = r - 1; i >= 1; --i) {
        for (int j = 1; j <= i; ++j) {
            // 状态转移方程：
            // 当前格子的最大路径和 = 自身数值 + 下方左、右两个可选路径的最大值
            dp[i][j] = a[i][j] + max(dp[i + 1][j], dp[i + 1][j + 1]);
        }
    }

    // 最终顶点 dp[1][1] 即为从最高点到底部任意处结束的最大路径权值和
    cout << dp[1][1] << "\n";

    return 0;
}
