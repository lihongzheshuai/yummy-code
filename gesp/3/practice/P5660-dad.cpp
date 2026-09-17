#include <iostream>
#include <string>

int main() {
    std::string str;
    std::cin >> str;
    int count = 0;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '1') {
            count++;
        }
    }
    std::cout << count;
    return 0;
}