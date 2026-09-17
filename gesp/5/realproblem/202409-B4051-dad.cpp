#include <cmath>
#include <iostream>

int n_c[100005];
int m_a[100005];
int main() {
    int n, m;
    std::cin >> n >> m;
    for (int i = 0; i < n; i++) {
        std::cin >> n_c[i];
    }
    for (int i = 0; i < m; i++) {
        std::cin >> m_a[i];
    }
    int ans = n_c[0];
    if (n == 1) {
        for (int i = 0; i < m; i++) {
            ans += m_a[i];
        }
    } else {
        for (int i = 1; i < n; i++) {
            ans = std::max(ans, n_c[i]);
        }

        for (int i = 0; i < m; i++) {
            if (m_a[i] > 0) {
                ans += m_a[i];
            }
        }
    }

    std::cout << ans;
    return 0;
}
