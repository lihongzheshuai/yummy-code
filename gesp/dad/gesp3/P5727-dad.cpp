#include <iostream>

int result_ary[105] = {0};
int main() {
    int n;
    std::cin >> n;
    result_ary[0] = n;
    int idx = 1;
    while (n != 1) {
        if (n % 2 == 0) {
            n /= 2;
        } else {
            n = n * 3 + 1;
        }
        result_ary[idx] = n;
        idx++;
    }
    for (int i = idx - 1; i >= 0; i--) {
        std::cout << result_ary[i] << " ";
    }
    return 0;
}