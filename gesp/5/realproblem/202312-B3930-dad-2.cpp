#include <iostream>
#include <vector>

int main() {
    int N;
    std::cin >> N;
    std::vector<int> a;

    for (int i = 0; i < N; ++i) {
        int x;
        std::cin >> x;
        a.push_back(x);
    }

    int ans = 0;
    // 题目中 a_i <= 2,147,483,647 -> 31 bits (0..30)
    for (int bit = 30; bit >= 0; --bit) {
        int candidate = ans | (1 << bit);
        int cnt = 0;
        // 统计满足 (x & candidate) == candidate 的元素数目（早停）
        for (int x : a) {
            if ((x & candidate) == candidate) {
                if (++cnt >= 2) {
                    break;
                }
            }
        }
        if (cnt >= 2) {
            ans = candidate;
        }
    }

    std::cout << ans << std::endl;
    return 0;
}
