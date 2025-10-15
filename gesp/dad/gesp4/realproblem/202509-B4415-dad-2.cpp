#include <iostream>

int num_ary[15][15];
int sum_ary[15][15];
int main() {
    int n, m;
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            std::cin >> num_ary[i][j];
            sum_ary[i][j] = sum_ary[i - 1][j] + sum_ary[i][j - 1] - sum_ary[i - 1][j - 1] + num_ary[i][j];
        }
    }
    int max_count = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = i; k <= n; k++) {
                for (int l = j; l <= m; l++) {
                    int temp_sum = sum_ary[k][l] - sum_ary[k][j - 1] - sum_ary[i - 1][l] + sum_ary[i - 1][j - 1];
                    if (temp_sum == (k - i + 1) * (l - j + 1)) {
                        max_count = std::max(max_count, temp_sum);
                    }
                }
            }
        }
    }

    std::cout << max_count << std::endl;
    return 0;
}