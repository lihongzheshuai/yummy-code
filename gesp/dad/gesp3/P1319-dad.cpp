#include <iostream>

int main() {
    int n;
    std::cin >> n;
    int cur_count;
    int cur_num = 0;
    int line_count = 0;
    while(std::cin >> cur_count) {
        for (int i = 0; i < cur_count; i++) {
            std::cout << cur_num;
            line_count++;
            if (line_count == n) {
                std::cout << "\n";
                line_count = 0;
            }
        }
        cur_num ^= 1;
    }
    return 0;
}