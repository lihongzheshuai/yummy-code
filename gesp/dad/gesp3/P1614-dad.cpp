#include <iostream>
#include <cmath>

int array[3005];
int main() {
    int n, m;
    std::cin >> n >> m;
    for (int i = 0; i < n; i++) {
        std::cin >> array[i];
    }
    int min_sum = 30000000;
    for (int i = 0; i <= n - m; i++) {
        int cur_sum = 0;
        for (int j = i; j < i + m; j++) {
            cur_sum += array[j];
        }
        min_sum = std::min(min_sum,cur_sum);
    }
    std::cout << min_sum;
    return 0;
}