#include <algorithm>
#include <iostream>
#include <sstream>

int main() {
    std::string str;
    std::getline(std::cin, str);
    std::stringstream ss(str);
    std::string token;
    while (std::getline(ss, token, ' ')) {
        reverse(token.begin(), token.end());
        std::cout << token << std::endl;
    }
    return 0;
}