#include <cmath>
#include <iostream>
#include <vector>

std::vector<int> square_nums;

bool is_lucky(int x) {
    for (int i = 0; i < square_nums.size(); i++) {
        if (x == square_nums[i] || x % square_nums[i] == 0) {
            return true;
        }
    }
    return false;
}

std::string luckyize(int x, int a) {
    if (is_lucky(x) && x >= a) {
        return "lucky";
    }

    int lucky_num;
    if (a >= x) {
        lucky_num = std::pow(std::ceil(std::sqrt(a)), 2);
    } else {
        lucky_num = square_nums[0] + x - x % square_nums[0];
        for (int i = 1; i < square_nums.size(); i++) {
            lucky_num = std::min(lucky_num, square_nums[i] + x - x % square_nums[i]);
        }
    }
    return std::to_string(lucky_num);
}

int main() {
    int a, N;
    std::cin >> a >> N;
    for (int i = 1; i <= 1001; i++) {
        if (i * i >= a) {
            square_nums.push_back(i * i);
        }
    }
    for (int i = 0; i < N; i++) {
        int x;
        std::cin >> x;
        std::cout << luckyize(x, a) << std::endl;
    }

    return 0;
}