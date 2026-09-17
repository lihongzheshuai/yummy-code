#include <iostream>
#include <string>

int main() {
    std::string str;
    std::cin >> str;
    if (!(str[0] >= 'a' && str[0] <= 'z') &&
        !(str[0] >= 'A' && str[0] <= 'Z') && str[0] != '_') {
        std::cout << "no";
        return 0;
    }
    for (int i = 0; i < str.length(); i++) {
        if (!(str[i] >= '0' && str[i] <= '9') &&
            !(str[i] >= 'a' && str[i] <= 'z') &&
            !(str[i] >= 'A' && str[i] <= 'Z') && str[i] != '_') {
            std::cout << "no";
            return 0;
        }
    }
    std::cout << "yes";
    return 0;
}