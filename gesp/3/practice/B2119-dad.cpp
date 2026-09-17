#include <iostream>
#include <string>

int main() {
    std::string str;
    std::cin >> str;
    size_t pos = str.rfind("er");
    if (pos == str.length() - 2) {
        std::cout << str.substr(0, pos) << std::endl;
        return 0;
    }
    pos = str.rfind("ly");
    if (pos == str.length() - 2) {
        std::cout << str.substr(0, pos) << std::endl;
        return 0;
    }
    pos = str.rfind("ing");
    if (pos == str.length() - 3) {
        std::cout << str.substr(0, pos) << std::endl;
        return 0;
    }
    std::cout << str;
    return 0;
}