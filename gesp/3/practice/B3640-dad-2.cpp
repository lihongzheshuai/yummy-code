#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string str;
    std::string result;
    while(std::cin >> str) {
        if (islower(str[0])) {
            transform(str.begin(), str.end(), str.begin(), ::toupper);
        } else if (isupper(str[0])) {
            transform(str.begin(), str.end(), str.begin(), ::tolower);
        } else {
            reverse(str.begin(), str.end());
        }
        result = str + result;
        result = " " + result;
    }
    std::cout << result.substr(1) << std::endl;
    return 0;
}