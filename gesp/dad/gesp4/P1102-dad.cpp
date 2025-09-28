#include <iostream>
#include <algorithm>

const int MAXN = 2 * 10e5 + 5;
long long num_ary[MAXN];
int main() {
    long long N, C;
    std::cin >> N >> C;

    long long ans = 0;
    for (int i = 0; i < N; i++) {
        std::cin >> num_ary[i];
    }
    std::sort(num_ary, num_ary + N);
    int left = 0, right = N - 1;
    while (left < right) {

    }
    std::cout << ans;
    return 0;
}