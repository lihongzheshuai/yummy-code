#include <iostream>
#include <string>

int main() {
    std::string str;
    std::getline(std::cin, str);
    int length = str.length();
    bool flag = true;
    int count = 0;
    for (int i = 0; i < length; i++) {
        if (str[i] == ' ') {
            if (count == 0) {
                continue;
            } else {
                if (flag) {
                    std::cout << count;
                    flag = false;
                } else {
                    std::cout << "," << count;
                }
                count = 0;
            }

        } else {
            count++;
        }
    }
    std::cout << "," << count;
    return 0;
}