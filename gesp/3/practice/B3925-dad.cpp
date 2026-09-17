#include <iostream>

int main() {
    int n, i;
    std::cin >> n >> i;
    for (int j = 1;; j++) {
        bool flag = true;
        int result = 0;
        for (int k = 0; k < n; k++) {
            if (k == 0) {
                result = j * n + i;
                continue;
            }
            if (result % (n - 1) != 0) {
                flag = false;
                break;
            } else {
                result = result / (n - 1) * n + i;
            }
        }
        if (flag) {
            std::cout << result;
            break;
        } else {
            continue;
        }
    }
    return 0;
}