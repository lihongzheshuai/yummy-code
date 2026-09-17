#include <cstdio>
#include <iostream>
#include <string>

int main() {
    std::string str1;
    std::string str2;
    std::getline(std::cin, str1);
    std::getline(std::cin, str2);
    if (str1.find(str2) != std::string::npos) {
        printf("%s is substring of %s", str2.c_str(), str1.c_str());
    } else if (str2.find(str1) != std::string::npos) {
        printf("%s is substring of %s", str1.c_str(), str2.c_str());
    } else {
        std::cout << "No substring";
    }
    return 0;
}