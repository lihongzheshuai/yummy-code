#include <cmath>
#include <iostream>
#include <string>

int ary[15][15];
int sum[15][15];

bool check(int f_row, int f_col, int l_row, int l_col) {
    int sum = 0;
    for (int i = f_row; i <= l_row; i++) {
        for (int j = f_col; j <= l_col; j++) {
            sum += ary[i][j];
        }
    }
    return sum == 0 ? true : false;
}

int main() {
    int n, m;
    std::cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        std::string r_str;
        std::cin >> r_str;
        for (int j = 1; j <= m; j++) {
            ary[i][j] = r_str[j - 1] == '0' ? -1 : 1;
            sum[i][j] =
                sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + ary[i][j];
        }
    }
    int max_area = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = i; k <= n; k++) {
                for (int l = j; l <= m; l++) {
                    if (check(i, j, k, l)) {
                        int area = (k - i + 1) * (l - j + 1);
                        max_area = std::max(max_area, area);
                    }
                }
            }
        }
    }
    std::cout << max_area;
    return 0;
}