#include <cctype>
#include <iostream>
#include <string>

int main() {
    int n;
    std::cin >> n;
    std::string str_ary[n];
    for (int i = 0; i < n; i++) {
        std::cin >> str_ary[i];
    }
    std::string out_ary[n];
    for (int i = 0; i < n; i++) {
        std::string cur_str = str_ary[i];
        if (std::islower(cur_str[0])) {
            cur_str[0] = std::toupper(cur_str[0]);
        }
        for (int j = 1; j < cur_str.length(); j++) {
            cur_str[j] = std::tolower(cur_str[j]);
        }
        out_ary[i] = cur_str;
    }
    for (int i = 0; i < n; i++) {
        std::cout << out_ary[i] << std::endl;
    }
    return 0;
}