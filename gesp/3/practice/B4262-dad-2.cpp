#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>

int main() {
    int n;
    std::cin >> n;
    int max_count = 0;
    std::string str_ary[n];
    int count_ary[n] = {0};
    int cur_idx = 0;
    while (n--) {
        std::string str;
        std::cin >> str;
        std::transform(str.begin(), str.end(), str.begin(), ::tolower);
        bool is_exist = false;
        for (int i = 0; i < cur_idx; i++) {
            if (str == str_ary[i]) {
                is_exist = true;
                count_ary[i]++;
                max_count = std::max(max_count, count_ary[i]);
                break;
            }
        }
        if (!is_exist) {
            str_ary[cur_idx] = str;
            count_ary[cur_idx]++;
            cur_idx++;
            max_count = std::max(max_count, count_ary[cur_idx - 1]);
        }
    }
    for (int i = 0; i < cur_idx; i++) {
        if (count_ary[i] == max_count) {
            std::cout << str_ary[i];
            break;
        }
    }
    return 0;
}