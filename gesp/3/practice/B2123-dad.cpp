#include <iostream>
#include <string>

int main() {
    std::string str;
    std::cin >> str;
    std::string result;
    int cur_count = 1;
    char cur_char = str[0];
    for (int i = 1; i < str.length();i++) {
        if (str[i] == cur_char) {
            cur_count++;
        } else {
            result += std::to_string(cur_count) + cur_char;
            cur_count = 1;
            cur_char = str[i];
        }
    }
    result += std::to_string(cur_count) + cur_char;
    std::cout << result;
    return 0;
}