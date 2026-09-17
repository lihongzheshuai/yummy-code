#include <iostream>

int buy_ary[1005][7];
int main() {
    int n;
    std::cin >> n;
    int target[7] = {0};
    for (int i = 0; i < 7; i++) {
        std::cin >> target[i];
    }
    int result[7] = {0};
    for (int i = 0; i < n; i++) {
        int count = 0;
        // 比较每一张彩票
        for (int j = 0; j < 7; j++) {
            std::cin >> buy_ary[i][j];
            for (int k = 0; k < 7; k++) {
                if (buy_ary[i][j] == target[k]) {
                    count++;
                }
            }
        }
        if (count) {
            result[7 - count]++;
        }
    }
    for (int i = 0; i < 7; i++) {
        std::cout << result[i] << " ";
    }
    return 0;
}