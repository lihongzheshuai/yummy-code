#include <iostream>
#include <string>

int main() {
    std::string str;
    std::string result;
    while(std::cin >> str) {
        if (str[0] >= 'a' && str[0] <= 'z') {
            for (int i = 0; i < str.length(); i++) {
                str[i] = str[i] - 'a' + 'A';
            }
            result = str + result;
        } else if (str[0] >= 'A' && str[0] <= 'Z') {
            for (int i = 0; i < str.length(); i++) {
                str[i] = str[i] - 'A' + 'a';
            }
            result = str + result;
        } else if (str[0] >= '0' && str[0] <= '9') {
            for (int i = 0; i < str.length(); i++) {
                result = str[i] + result;
            }
        }
        result = " " + result;
    }
    std::cout << result.substr(1) << std::endl;
    return 0;
}