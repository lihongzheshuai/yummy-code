#include <iostream>

int points[605];
int main() {
    int n, w;
    std::cin >> n >> w;
    int line_point = 1000;

    for (int i = 1; i <= n; i++) {
        int x;
        std::cin >> x;
        points[x]++;
        int count = std::max(1, i * w / 100);
        for (int j = 600; j >= 0; j--) {
            if (points[j] >= count) {
                line_point = j;
                break;
            } else {
                count -= points[j];
            }
        }
        std::cout << line_point << " ";
    }

    return 0;
}