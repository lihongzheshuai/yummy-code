#include <iostream>
#include <string>

int main() {
    std::string str;
    std::cin >> str;
    if (str.substr(str.length() - 2, str.length()) == "er" ||
        str.substr(str.length() - 2, str.length()) == "ly") {
        std::cout << str.substr(0, str.length() - 2) << std::endl;
    } else if (str.substr(str.length() - 3, str.length()) == "ing") {
        std::cout << str.substr(0, str.length() - 3) << std::endl;
    } else {
        std::cout << str;
    }

    return 0;
}