/**
 * 题目: 【GESP真题】GESP五级 / CSP-J 题解：luogu-P17456 [GESP202609 五级] 饮品调制
 * 题号: P17456
 * 归属: GESP5级 (202609认证真题)
 * 博客: https://www.coderli.com/gesp-5-luogu-p17456-beverage-mix/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

/**
 * Problem: luogu-P17456
 * Standard: C++11 (CCF GESP 官方大纲规范)
 * Author: OneCoder
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Item {
    double v;
    double s;
    double diff; // |s - t|
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    double t;
    if (!(cin >> n >> t)) {
        return 0;
    }

    double zero_vol = 0.0;
    vector<Item> pos;
    vector<Item> neg;
    double total_pos = 0.0;
    double total_neg = 0.0;

    for (int i = 0; i < n; ++i) {
        double v, s;
        cin >> v >> s;
        if (s == t) {
            zero_vol += v;
        } else if (s > t) {
            pos.push_back({v, s, s - t});
            total_pos += v * (s - t);
        } else {
            neg.push_back({v, s, t - s});
            total_neg += v * (t - s);
        }
    }

    // 贪心排序：diff 越小，每单位贡献换取的体积越大
    sort(pos.begin(), pos.end(), [](const Item& a, const Item& b) {
        return a.diff < b.diff;
    });
    sort(neg.begin(), neg.end(), [](const Item& a, const Item& b) {
        return a.diff < b.diff;
    });

    double balance_w = min(total_pos, total_neg);

    if (balance_w == 0.0 && zero_vol == 0.0) {
        cout << "0.000\n";
        return 0;
    }

    double ans_vol = zero_vol;

    // 贪心满足正侧 balance_w
    double need_pos = balance_w;
    for (const auto& item : pos) {
        if (need_pos <= 0) break;
        double max_give = item.v * item.diff;
        if (need_pos >= max_give) {
            ans_vol += item.v;
            need_pos -= max_give;
        } else {
            ans_vol += need_pos / item.diff;
            need_pos = 0;
        }
    }

    // 贪心满足负侧 balance_w
    double need_neg = balance_w;
    for (const auto& item : neg) {
        if (need_neg <= 0) break;
        double max_give = item.v * item.diff;
        if (need_neg >= max_give) {
            ans_vol += item.v;
            need_neg -= max_give;
        } else {
            ans_vol += need_neg / item.diff;
            need_neg = 0;
        }
    }

    cout << fixed << setprecision(3) << ans_vol << "\n";

    return 0;
}
