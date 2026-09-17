/**
 * 题目: 【GESP】C++三级、四级练习 luogu-P2089 烤鸡
 * 题号: P2089
 * 归属: GESP3级
 * 解法: 解法 2 / 共 3 种解法
 * 博客: https://www.coderli.com/gesp-3-luogu-p2089/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) {
        return 0;
    }

    // 边界特判
    if (n < 10 || n > 30) {
        cout << 0 << "\n";
        return 0;
    }

    // 暂存所有合法方案
    vector<vector<int>> results;

    // 10 重嵌套循环直接枚举每种配料的克数 (1 ~ 3)
    for (int a = 1; a <= 3; ++a) {
        for (int b = 1; b <= 3; ++b) {
            for (int c = 1; c <= 3; ++c) {
                for (int d = 1; d <= 3; ++d) {
                    for (int e = 1; e <= 3; ++e) {
                        for (int f = 1; f <= 3; ++f) {
                            for (int g = 1; g <= 3; ++g) {
                                for (int h = 1; h <= 3; ++h) {
                                    for (int i = 1; i <= 3; ++i) {
                                        for (int j = 1; j <= 3; ++j) {
                                            if (a + b + c + d + e + f + g + h + i + j == n) {
                                                results.push_back({a, b, c, d, e, f, g, h, i, j});
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    // 输出方案总数
    cout << results.size() << "\n";

    // 逐行输出方案
    for (const auto& scheme : results) {
        for (int k = 0; k < 10; ++k) {
            cout << scheme[k] << (k == 9 ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}
