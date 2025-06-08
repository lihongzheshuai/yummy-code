#include <cmath>
#include <iostream>

int main() {
    int N;
    std::cin >> N;
    int one_ary[N];
    int two_ary[N];
    int three_ary[N];
    for (int i = 0; i < N; i++) {
        std::cin >> one_ary[i] >> two_ary[i] >> three_ary[i];
    }
    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (std::abs(one_ary[j] - one_ary[i]) <= 5 &&
                std::abs(two_ary[j] - two_ary[i]) <= 5 &&
                std::abs(three_ary[j] - three_ary[i]) <= 5 &&
                std::abs(one_ary[i] + two_ary[i] + three_ary[i] -
                         (one_ary[j] + two_ary[j] + three_ary[j])) <= 10) {
                count++;
            }
        }
    }
    std::cout << count << std::endl;
    return 0;
}