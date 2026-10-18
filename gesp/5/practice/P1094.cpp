/**
 * 题目: 【NOIP真题】2007 纪念品分组 luogu-P1094 | 适用于 GESP五级 / CSP-J 练习
 * 题号: P1094
 * 归属: GESP5级 / NOIP 2007 普及组
 * 博客: https://www.coderli.com/noip-2007-luogu-p1094/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <algorithm>

using namespace std;

// 纪念品总件数 n 最大为 3 * 10^4，声明在全局静态存储区
const int MAXN = 30005;
int p[MAXN];

int main() {
    int w, n;
    // 读取每组纪念品价格之和的上限 w 与纪念品总件数 n
    cin >> w >> n;

    // 依次读取每件纪念品的价格（下标从 1 到 n）
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
    }

    // 第一步：将所有纪念品按价格从小到大升序排序
    sort(p + 1, p + n + 1);

    // 第二步：利用相向双指针 l 和 r 进行首尾贪心配对
    int l = 1;      // 左指针，指向当前剩余最便宜的纪念品
    int r = n;      // 右指针，指向当前剩余最昂贵的纪念品
    int ans = 0;    // 统计最终的最少分组数目

    while (l <= r) {
        // 如果当前最贵的 p[r] 能与当前最便宜的 p[l] 合装在一组（价格之和不超过 w）
        // 注意：当 l == r（仅剩最后一件纪念品）时，即便触发 l++ 和 r-- 也会立刻满足 l > r 退出循环，ans 同样只加 1
        if (p[l] + p[r] <= w) {
            l++;    // 最便宜的这一件成功搭车，左指针右移
            r--;    // 最贵的这一件完成分组，右指针左移
        } else {
            // 如果连最便宜的 p[l] 都无法与 p[r] 合装，说明 p[r] 无法与任何剩余物品配对
            r--;    // 最贵的这一件只能单独成组，右指针左移
        }
        ans++;      // 无论合装还是单独成组，都消耗了 1 个分组
    }

    // 输出最少的分组数目
    cout << ans << "\n";

    return 0;
}
