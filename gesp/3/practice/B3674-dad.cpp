#include <iostream>
#include <string>

int main() {
    std::string str;
    getline(std::cin, str);
    int idx = 1;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] != ' ') {
            if (idx % 2 == 1) {
                str[i] = toupper(str[i]);
            } else {
                str[i] = tolower(str[i]);
            }
            idx++;
        } else {
            idx = 1;
        }
    }
    std::cout << str;
    return 0;
}