#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
typedef long long ll;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<ll>> a(n + 1);

    for (int i = 0; i < m; i++) {
        ll p, c;
        std::cin >> p >> c;
        a[p].push_back(c);
    }

    for (int i = 2; i <= n; i++) {
        std::sort(a[i].begin(), a[i].end());
    }
    int first_cnt = a[1].size();
    ll ans = LLONG_MAX;
    for (int x = first_cnt; x <= m; x++) {
        int target = x - 1;
        int move = 0;
        ll move_money = 0;
        std::vector<ll> pool;
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < (int)a[i].size(); j++) {
                if (j < (int)a[i].size() - target) {
                    move_money += a[i][j];
                    move++;
                } else {
                    pool.push_back(a[i][j]);
                }
            }
        }
        int new_first_cnt = a[1].size() + move;
        if (new_first_cnt < x) {
            if (pool.size() < x - new_first_cnt) {
                continue;
            }
            std::sort(pool.begin(), pool.end());
            for (int i = 0; i < x - new_first_cnt; i++) {
                move_money += pool[i];
            }
        }
        ans = std::min(ans, move_money);
    }
    std::cout << ans << std::endl;
    return 0;
}