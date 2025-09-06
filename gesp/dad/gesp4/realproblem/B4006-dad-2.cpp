#include <algorithm>
#include <iostream>

int val_arys[1005];
int pre_sum[1005];
int main() {
    int n, k;
    std::cin >> n >> k;
    for (int i = 0; i < n; i++) {
        std::cin >> val_arys[i];
    }
    std::sort(val_arys, val_arys + n);
    pre_sum[0] = val_arys[0];
    for (int i = 1; i < n; i++) {
        pre_sum[i] = pre_sum[i - 1] + val_arys[i];
    }
    int max_sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (val_arys[j] - val_arys[i] <= k) {
                max_sum =
                    std::max(max_sum, pre_sum[j] - pre_sum[i] + val_arys[i]);
            } else {
                break;
            }
        }
    }

    std::cout << max_sum;
    return 0;
}
