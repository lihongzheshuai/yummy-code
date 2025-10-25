#include <cmath>
#include <iostream>

int lucky_nums[1002100];

int main() {
    int a, N;
    std::cin >> a >> N;
    for (int i = std::ceil(std::sqrt(a)); i <= 1001; i++) {
        int square_num = i * i;
        lucky_nums[square_num] = 1;
        for (int j = 2; j * square_num <= 1002000; j++) {
            lucky_nums[j * square_num] = 1;
        }
    }
    for (int i = 0; i < N; i++) {
        int x;
        std::cin >> x;
        if (lucky_nums[x]) {
            std::cout << "lucky" << std::endl;
        } else {
            int max_n = std::max(x, a);
            for (int j = max_n; j <= 1002100; j++) {
                if (lucky_nums[j]) {
                    std::cout << j << std::endl;
                    break;
                }
            }
        }
    }

    return 0;
}