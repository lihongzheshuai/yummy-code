#include <iostream>

int main() {
    int n;
    std::cin >> n;
    int count = 0;
    for (int i = 1; i <= n; i++) {
        bool flag = true;
        int cur_num = i;
        if (i < 10) {
            count++;
        } else {
            int last_bit = cur_num % 10;
            cur_num /= 10;
            while (cur_num > 0) {
                int cur_bit = cur_num % 10;
                if (cur_bit != last_bit) {
                    flag = false;
                    break;
                }
                cur_num /= 10;
            }
            if (flag) {
                count++;
            }
        }
    }
    std::cout << count;
    return 0;
}