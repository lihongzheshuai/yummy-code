#include <algorithm>
#include <iostream>

int val_arys[1005];
int main() {
    int n, k;
    std::cin >> n >> k;
    for (int i = 0; i < n; i++) {
        std::cin >> val_arys[i];
    }
    std::sort(val_arys, val_arys + n);
    int max_sum = 0;
    int left = 0;
    int cur_sum = 0;
    for (int right = 0; right < n; right++) {
        cur_sum += val_arys[right]; 
        while(val_arys[right] - val_arys[left] > k) {
            cur_sum -= val_arys[left];
            left++;
        }
        max_sum = std::max(max_sum, cur_sum);
    }

    std::cout << max_sum;
    return 0;
}
