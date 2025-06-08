#include <iostream>
#include <string>

int main() {
    std::string str_ary[501];
    int cur_idx = -1;
    while (true) {
        cur_idx++;
        std::cin >> str_ary[cur_idx];
        if (str_ary[cur_idx] == "0") {
            break;
        }
        bool is_exist = false;
        for (int i = 0; i < cur_idx; i++) {
            if (str_ary[i] == str_ary[cur_idx]) {
                is_exist = true;
                break;
            }
        }
        if (!is_exist) {
            std::cout << str_ary[cur_idx];
        }
    }
    return 0;
}