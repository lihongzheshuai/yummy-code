#include <iostream>

int num_ary[15][15];
int main() {
    int n, m;
    std::cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> num_ary[i][j];
        }
    }
    int max_count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = i; k < n; k++) {
                for (int l = j; l < m; l++) {
                    int count = 0;
                    bool flag = true;
                    for (int x = i; x <= k; x++) {
                        for (int y = j; y <= l; y++) {
                            if (num_ary[x][y] == 1) {
                                count++;
                            } else {
                                flag = false;
                                count = 0;
                                break;
                            }
                        }
                        if (!flag) {
                            break;
                        }
                    }
                    max_count = std::max(max_count, count);
                }
            }
        }
    }
    std::cout << max_count << std::endl;
    return 0;
}