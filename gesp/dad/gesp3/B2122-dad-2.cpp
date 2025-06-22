#include <string>
#include <iostream>

int main() {
    std::string str;
    std::getline(std::cin, str);
    std::string cur_str;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ' ') {
            std::cout << cur_str << std::endl;
            cur_str = "";
        } else {
            cur_str = str[i] + cur_str;
        }
    }
    std::cout << cur_str << std::endl;
    return 0;
}