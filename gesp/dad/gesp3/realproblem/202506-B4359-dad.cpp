#include <iostream>

int main() {
    int n;
    std::cin >> n;
    long long sum = 0;
    int last_count = 0;
    for (int i = 0; i < n; i++) {
        int a;
        std::cin >> a;
        if (a > last_count) {
            sum += a;
            last_count = a;
        } else {
            sum += last_count + 1;
            last_count = last_count + 1;
        }
    }
    std::cout << sum << std::endl;
    return 0;
}