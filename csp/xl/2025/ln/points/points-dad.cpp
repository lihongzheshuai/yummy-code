#include <algorithm>
#include <climits>
#include <iostream>

long long a_array[1005][1005];
long long pre_sum[1005][1005];
int main() {
    freopen("points.in", "r", stdin);
    freopen("points.out", "w", stdout);
    int n, m, x, y;
    std::cin >> n >> m >> x >> y;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            std::cin >> a_array[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            pre_sum[i][j] = pre_sum[i - 1][j] + pre_sum[i][j - 1] -
                            pre_sum[i - 1][j - 1] + a_array[i][j];
        }
    }

    long long max_x_points = LLONG_MIN; // 初始化为最小值
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i + x - 1 <= n && j + x - 1 <= m) {
                long long cur_points =
                    pre_sum[i + x - 1][j + x - 1] - pre_sum[i - 1][j + x - 1] -
                    pre_sum[i + x - 1][j - 1] + pre_sum[i - 1][j - 1];
                max_x_points = std::max(max_x_points, cur_points);
            } else {
                break;
            }
        }
    }

    long long max_y_points = LLONG_MIN;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i + y - 1 <= n && j + y - 1 <= m) {
                long long cur_points =
                    pre_sum[i + y - 1][j + y - 1] - pre_sum[i - 1][j + y - 1] -
                    pre_sum[i + y - 1][j - 1] + pre_sum[i - 1][j - 1];
                max_y_points = std::max(max_y_points, cur_points);
            } else {
                break;
            }
        }
    }

    long long max_points = std::max(max_x_points, max_y_points);
    std::cout << max_points << std::endl;
    return 0;
}
