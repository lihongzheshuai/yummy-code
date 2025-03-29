#include <iostream>
#include <string>

int main() {
    std::string str;
    std::cin >> str;
    int str_ary[26] = {0};
    char idx = 'a';
    for (int i = 0; i < str.size(); i++) {
        str_ary[str[i] - idx]++;
    }
    for (int i = 0; i < str.size(); i++) {
        if (str_ary[str[i] - idx] == 1) {
            std::cout << (char)str[i] << std::endl;
            return 0;
        }
    }
    std::cout << "no";
    return 0;
}
