#include <algorithm>
#include <iostream>

int val_arys[1005];
int main() {
    int n, k;
    std::cin >> n >> k;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> val_arys[i];
        sum += val_arys[i];
    }
    std::sort(val_arys, val_arys + n);

    int max_sum = 0;
    for (int i = 0; i < n; i++) {
        int temp_sum = sum;
        for (int j = n - 1; j >= i; j--) {
            if (val_arys[j] - val_arys[i] <= k) {
                max_sum = std::max(max_sum, temp_sum);
                break;
            } else {
                temp_sum -= val_arys[j];
            }
        }
        sum -= val_arys[i];
    }
    std::cout << max_sum;
    return 0;
}
