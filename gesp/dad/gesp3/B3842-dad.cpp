#include <iostream>

int main() {
    int m, n;
    std::cin >> n >> m;
    int n_ary[n] = {0};
    int m_ary[m];
    for (int i = 0; i < m; i++) {
        std::cin >> m_ary[i];
    }
    for (int i = 0; i < n; i++) {
        n_ary[i] = 0;
    }
    for (int i = 0; i < m; i++) {
        n_ary[m_ary[i]] = 1;
    }
    bool flag = true;
    for (int i = 0; i < n; i++) {
        if (n_ary[i] == 0) {
            std::cout << i << " ";
            flag = false;
        }
    }
    if (flag) {
        std::cout << n;
    }
    return 0;
}