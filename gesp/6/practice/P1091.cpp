/**
 * 题目: 【NOIP真题】2004 合唱队形 luogu-P1091 | 适用于 GESP6级 / CSP-J 练习
 * 题号: P1091
 * 归属: GESP六级 / CSP-J / NOIP2004 提高组
 * 博客: https://www.coderli.com/gesp-6-luogu-p1091/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 最大人数 N <= 100，设置全局安全边界
const int MAXN = 105;

// t 数组存储每位同学的身高（厘米）
int t[MAXN];
// dp_left[i] 表示以第 i 位同学为结尾的最长严格上升子序列（LIS）长度
int dp_left[MAXN];
// dp_right[i] 表示以第 i 位同学为起点的最长严格下降子序列（LDS）长度
int dp_right[MAXN];

int main() {
    int n;
    cin >> n;

    // 读入每位同学的身高，下标从 1 开始
    for (int i = 1; i <= n; ++i) {
        cin >> t[i];
    }

    // 1. 正向动态规划：计算以每位同学为结尾的最长严格上升子序列长度
    for (int i = 1; i <= n; ++i) {
        dp_left[i] = 1; // 基础情况：自身至少构成长度为 1 的子序列
        for (int j = 1; j < i; ++j) {
            // 严格递增条件
            if (t[j] < t[i]) {
                dp_left[i] = max(dp_left[i], dp_left[j] + 1);
            }
        }
    }

    // 2. 反向动态规划：计算以每位同学为起点的最长严格下降子序列长度
    // 逆向遍历等价于求从右往左看的最长上升子序列
    for (int i = n; i >= 1; --i) {
        dp_right[i] = 1; // 基础情况：自身至少构成长度为 1 的子序列
        for (int j = n; j > i; --j) {
            // 严格递减条件（后方同学身高小于当前同学）
            if (t[j] < t[i]) {
                dp_right[i] = max(dp_right[i], dp_right[j] + 1);
            }
        }
    }

    // 3. 枚举最高峰顶（C位）的位置 i，寻找保留人数最多的合唱队形
    int max_retain = 0;
    for (int i = 1; i <= n; ++i) {
        // 第 i 位同学在左侧上升末尾和右侧下降起点各计算了一次，去重减 1
        int current_k = dp_left[i] + dp_right[i] - 1;
        max_retain = max(max_retain, current_k);
    }

    // 4. 最少出列人数 = 总人数 - 最多保留人数
    cout << n - max_retain << endl;

    return 0;
}
