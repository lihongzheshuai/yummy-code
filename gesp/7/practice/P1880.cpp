/**
 * 题目: 【GESP/CSP练习】GESP七级 / CSP-S 题解：luogu-P1880 [NOI1995] 石子合并
 * 题号: P1880
 * 归属: GESP七级 / CSP-S / 区间动态规划经典题
 * 博客: https://www.coderli.com/gesp-7-luogu-p1880/
 * 标准: C++11 (严格遵循 CCF GESP 官方规范)
 */

#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

// 最大石子堆数常量定义
// 题目中 N <= 100，破环成链复制后最大长度为 2N = 200
const int MAXN = 205;
const int INF = 1e9; // 极大值常量，用于最小值得分初始化

// a 数组存储石子数量，prefix_sum 存储前缀和
int a[MAXN];
int prefix_sum[MAXN];

// dp_min[i][j]: 将区间 [i, j] 内的石子合并成一堆的最小得分
// dp_max[i][j]: 将区间 [i, j] 内的石子合并成一堆的最大得分
int dp_min[MAXN][MAXN];
int dp_max[MAXN][MAXN];

int main() {
    int n;
    cin >> n;

    // 读入原始 n 堆石子的数量，并将序列复制一份扩展到 2n，完成环形破环成链
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i + n] = a[i];
    }

    // 计算扩展后长度为 2n 的前缀和数组
    prefix_sum[0] = 0;
    for (int i = 1; i <= 2 * n; ++i) {
        prefix_sum[i] = prefix_sum[i - 1] + a[i];
    }

    // 初始化 DP 状态矩阵
    // 单堆石子（i == j）无需合并，得分为 0；其余状态赋初始极值
    for (int i = 1; i <= 2 * n; ++i) {
        for (int j = 1; j <= 2 * n; ++j) {
            if (i == j) {
                dp_min[i][j] = 0;
                dp_max[i][j] = 0;
            } else {
                dp_min[i][j] = INF;
                dp_max[i][j] = -1;
            }
        }
    }

    // 区间 DP 阶段递推：外层枚举合并区间的长度 len，从 2 递增至 n
    for (int len = 2; len <= n; ++len) {
        // 枚举区间的左端点 i，保证右端点 j 在合法范围 2n 之内
        for (int i = 1; i + len - 1 <= 2 * n; ++i) {
            int j = i + len - 1; // 当前区间的右端点
            int sum_val = prefix_sum[j] - prefix_sum[i - 1]; // 合并该区间产生的固定累计得分

            // 枚举最后一次合并的分割点 k，将区间分为 [i, k] 与 [k + 1, j] 两部分
            for (int k = i; k < j; ++k) {
                dp_min[i][j] = min(dp_min[i][j], dp_min[i][k] + dp_min[k + 1][j] + sum_val);
                dp_max[i][j] = max(dp_max[i][j], dp_max[i][k] + dp_max[k + 1][j] + sum_val);
            }
        }
    }

    // 遍历所有可能的环形起点 i (1 <= i <= n)，统计长度为 n 的闭区间合并极值
    int ans_min = INF;
    int ans_max = -1;
    for (int i = 1; i <= n; ++i) {
        ans_min = min(ans_min, dp_min[i][i + n - 1]);
        ans_max = max(ans_max, dp_max[i][i + n - 1]);
    }

    // 按题目要求输出两行结果：第一行最小得分，第二行最大得分
    cout << ans_min << endl;
    cout << ans_max << endl;

    return 0;
}
