#include <iostream>
#include <vector>

int pre_sum[105][105];
int main() {
    int n, m,k;
    std::cin >> n >> m >> k;

    std::vector<std::string> strs(n);
    for (int i = 0; i < n; i++) {
        std::cin >> strs[i];
    }
    pre_sum[0][0] = strs[0][0] == '1' ? 1 : 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            pre_sum[i+1][j+1] = pre_sum[i][j+1] + pre_sum[i+1][j] - pre_sum[i][j] + (strs[i][j] == '1' ? 1 : 0);
        }
    }
    bool flag = false;
    int min_count = n * m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int l = i; l <= n; l++) {
                for (int r = j; r <= m; r++) {
                    int cur_count = pre_sum[l][r] - pre_sum[i-1][r] - pre_sum[l][j-1] + pre_sum[i-1][j-1];
                    if (cur_count >= k) {
                        min_count = std::min(min_count, (l - i + 1) * (r - j + 1));
                        flag = true;
                    }
                }
            }
        }
    }
    if (flag) {
        std::cout << min_count << std::endl;
    } else {
        std::cout << 0 << std::endl;
    }
    return 0;
}