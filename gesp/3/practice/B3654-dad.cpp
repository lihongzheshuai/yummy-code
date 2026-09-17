#include <iostream>
#include <string>

int main() {
    std::string cur_str;
    std::string str_ary[500];
    std::string result_str;
    int cur_idx = 0;
    while (true) {
        std::cin >> cur_str;
        if (cur_str == "0") {
            break;
        }
        bool is_exist = false;
        for (int i = 0; i < cur_idx; i++) {
            if (str_ary[i] == cur_str) {
                is_exist = true;
                break;
                ;
            }
        }
        if (!is_exist) {
            str_ary[cur_idx] = cur_str;
            cur_idx++;
        }
    }
    for (int i = 0; i < cur_idx; i++) {
        std::cout << str_ary[i];
    }
    return 0;
}