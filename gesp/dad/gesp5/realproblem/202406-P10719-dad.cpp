#include <iostream>
#include <vector>
int main() {
    int n, m,k;
    std::cin >> n >> m >> k;

    std::vector<std::string> strs(n);
    for (int i = 0; i < n; i++) {
        std::cin >> strs[i];
    }
    int min_count = n * m;
    bool flag = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int l = i; l < n; l++) {
                for (int r = j; r < m; r++) {
                    int cur_count = 0;
                    for (int x = i; x <= l; x++) {
                        for (int y = j; y <= r; y++) {
                            if (strs[x][y] == '1') {
                                cur_count++;
                            }
                            if (cur_count == k) {
                                // std::cout << i << " " << j << " " << l << " " << r << std::endl;
                                min_count = std::min(min_count, (l - i + 1) * (r - j + 1));
                                flag = true;
                            }
                        }
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
}