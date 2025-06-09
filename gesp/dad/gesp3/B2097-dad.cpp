#include<iostream>
#include<cmath>

int main() {
    int n;
    std::cin >> n;
    int count = 0;
    int max_n = 0;
    int last_num = -1;
    while (n--) {
        int cur_num;
        std::cin >> cur_num;
        if (last_num == -1) {
            last_num = cur_num;
            count++;
            continue;
        }
        if (cur_num == last_num) {
            count++;
        } else {
            max_n = std::max(max_n, count);
            last_num = cur_num;
            count = 1;
        }

    }
    std::cout << max_n;
    return 0;
}