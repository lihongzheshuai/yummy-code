#include <iostream>
#include <cmath>
#include <algorithm>

int a[1000005];
int main() {
    int N;
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::cin >> a[i];
    }
    std::sort(a, a + N);
    int limit = std::min(N, 100);
    int max_a = -1;
    for (int i = N - 1; i > N - limit - 1; i--) {
        for (int j = i - 1; j > N - limit - 1; j--) {
            max_a = std::max(max_a, a[i] & a[j]);
        }
    }
    std::cout << max_a << std::endl;
    return 0;
}