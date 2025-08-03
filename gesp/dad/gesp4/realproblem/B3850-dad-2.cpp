#include <iostream>

int sum_digit(int num) {
    int sum = 0;
    while (num != 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int trans_num(int num) {
    int sum = num * 7;
    while(sum > 9) {
        sum = sum_digit(sum);
    }
    return sum;
}

bool is_lucky_num(long long num) {
    int sum = 0;
    int idx = 0;
    while (num != 0) {
        int c_num = num % 10;
        if (idx % 2 == 0) {
            c_num = sum_digit(trans_num(c_num));
        }
        sum += c_num;
        num /= 10;
        idx++;
    }
    if (sum % 8 == 0) {
        return true;    
    }
    return false;
}

int main() {
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        long long number;
        std::cin >> number;
        if (is_lucky_num(number)) {
            std::cout << 'T' << "\n";
        } else {
            std::cout << 'F' << "\n";
        }
    }
    return 0;
}
