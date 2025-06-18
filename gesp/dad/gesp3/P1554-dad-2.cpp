#include <iostream>

int main() {
    int m, n;
    std::cin >> m >> n;
    int result[10] = {0};
    for (int i = m; i <= n; i++) {
        int t = i;
        while (t) {
            result[t % 10]++;
            t /= 10;
        }
    }
    for (int i = 0; i < 10; i++) {
        std::cout << result[i] << " ";
    }
    return 0;
}