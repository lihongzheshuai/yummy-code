#include <iostream>
#include <string>

int main() {
    std::string str;
    std::getline(std::cin, str);
    std::string r_str = std::string(str.size(), '\0');
    for (int i = 0; i < str.size(); i++) {
        if (i == str.size() - 1) {
            r_str[i] = str[str.size() - 1] + str[0];
        } else {
            r_str[i] = str[i] + str[i + 1];
        }
    }
    std::cout << r_str;
    return 0;
}