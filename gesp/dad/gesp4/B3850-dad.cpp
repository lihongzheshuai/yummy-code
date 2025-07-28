#include <iostream>
#include <string>

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
    std::string num_str = std::to_string(num);
    int sum = 0;
    for (int i = 0; i < num_str.length(); i++) {
        if (i % 2 == 0) {
            int c_num = num_str[num_str.length() -1 -i] - '0';
            c_num = trans_num(c_num);
            num_str[num_str.length() -1 -i] = char(c_num + '0');
        }
        sum += num_str[num_str.length() -1 -i] - '0';
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
