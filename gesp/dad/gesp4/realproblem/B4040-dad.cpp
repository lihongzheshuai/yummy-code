#include <iostream>
#include <string>

std::string str_ary[105];
bool check(int x, int y, int n, int m) {
    if (x + 4 >= n || y + 4 >= m) {
        return false;
    }
    for (int i = x; i < x + 4; i++) {
        for (int j = y; j < y + 4; j++) {
            if (i == x || i == x + 3) {
                if (str_ary[i][j] != '0') {
                    return false;
                }
            }
            if (j == y || j == y + 3) {
                if (str_ary[i][j] != '0') {
                    return false;
                }
            }
            if ((i == x + 1 || i == x + 2) && (j == y + 1 || j == y + 2)) {
                if (str_ary[i][j] != '1') {
                    return false;
                }
            }
        }
    }
    return true;
}
int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n, m;
        std::cin >> n >> m;
        for (int i = 0; i < n; i++) {
            std::cin >> str_ary[i];
        }
        bool flag = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (check(i, j, n, m)) {
                    std::cout << "Yes" << std::endl;
                    flag = true;
                    break;
                }
            }
            if (flag) {
                break;
            }
        }
        if (!flag) {
            std::cout << "No" << std::endl;
        }
    }
    return 0;
}