#include <cmath>
#include <iostream>
#include <string>

int ary[15][15];
int sum[15][15];
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
                    int area_sum = sum[k][l] - sum[i - 1][l] - sum[k][j - 1] +
                                   sum[i - 1][j - 1];
                    if (area_sum == 0) {
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