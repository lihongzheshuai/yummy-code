/**
 * 题目: 【GESP】C++五级真题（贪心和剪枝思想） luogu-B3930 [GESP202312 五级] 烹饪问题
 * 题号: B3930
 * 归属: GESP5级 (202312认证真题)
 * 解法: 解法 3 / 共 3 种解法
 * 博客: https://www.coderli.com/gesp-5-luogu-b3930/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;

    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    int ans = 0;

    // 动态收缩候选池：每确认一位，就直接剔除不满足该位的食材
    for (int bit = 30; bit >= 0; --bit) {
        int candidate = ans | (1 << bit);
        int cnt = 0;

        for (int x : a) {
            if ((x & candidate) == candidate) {
                if (++cnt >= 2) break;
            }
        }

        if (cnt >= 2) {
            ans = candidate;
            // 剪枝过滤：只保留满足 candidate 的数
            vector<int> filtered;
            filtered.reserve(a.size());
            for (int x : a) {
                if ((x & candidate) == candidate) {
                    filtered.push_back(x);
                }
            }
            a = move(filtered);

            // 若候选池只剩下 2 个数，答案就是两者之与，可直接提前结束
            if (a.size() == 2) {
                ans = a[0] & a[1];
                break;
            }
        }
    }

    cout << ans << "\n";
    return 0;
}
