/**
 * 题目: 【GESP】C++五级真题（贪心和剪枝思想） luogu-B3930 [GESP202312 五级] 烹饪问题
 * 题号: B3930
 * 归属: GESP5级 (202312认证真题)
 * 解法: 解法 2 / 共 3 种解法
 * 博客: https://www.coderli.com/gesp-5-luogu-b3930/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <vector>

using namespace std;

// 开启快读优化以应对 N = 10^6
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;                       // 食材总数
    if (!(cin >> N)) return 0;

    vector<int> a(N);            // 存储每种食材的美味度
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    int ans = 0;                 // 最终答案：最高契合度（按位与最大值）

    // 题目中 a_i ≤ 2,147,483,647 = 2^31 - 1，二进制位最高为第 30 位
    // 从最高位到最低位逐位贪心试探
    for (int bit = 30; bit >= 0; --bit) {
        int candidate = ans | (1 << bit);   // 试探把当前 bit 位置 1
        int cnt = 0;                        // 统计满足 (x & candidate) == candidate 的食材个数

        // 遍历所有食材进行早停剪枝：找到 2 个及以上即可立即确认
        for (int x : a) {
            if ((x & candidate) == candidate) { // x 包含 candidate 的所有置位
                if (++cnt >= 2) {
                    break;                  // 剪枝：已有 2 个食材满足，提前退出
                }
            }
        }

        // 若存在至少 2 个食材支持该掩码，则确认保留当前位
        if (cnt >= 2) {
            ans = candidate;
        }
    }

    cout << ans << "\n";          // 输出最高契合度
    return 0;
}
