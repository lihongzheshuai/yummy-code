#include <iostream>
#include <cmath>

int a[1000005];
int main() {
    int N;
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::cin >> a[i];
    }
    int max_a = -1;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            max_a = std::max(max_a, a[i] & a[j]);
        }
    }
    std::cout << max_a << std::endl;
    return 0;
}