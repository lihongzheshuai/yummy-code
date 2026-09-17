#include <iostream>
#include <string>

int main() {
    std::string str;
    int max_count = 0;
    std::string max_str;
    while(std::cin >> str) {
        if (str.back() == '.') {
            str.pop_back();
        }
        int str_length = str.length();
        if (str_length > max_count) {
            max_count = str_length;
            max_str = str;
        }
    }
    std::cout << max_str << std::endl;
    return 0;
}