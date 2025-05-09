#include <iostream>

int main() {
    int N, D;
    std::cin >> N >> D;
    int ary[N] = {0};
    for (int i = 1; i <= D; i++) {
        int idx;
        std::cin >> idx;
        ary[idx] += i;
    }
    for (int i = 0; i< N; i++) {
        std::cout << ary[i] << " ";
    }
    return 0;
}