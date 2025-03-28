#include <iostream>
#include <string>

int main() {
    std::string str;
    std::getline(std::cin, str);
    int count = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            count++;
        }
    }
    std::cout << count << std::endl;
    return 0;
}