#include <iostream>
#include <string>

int main() {
    std::string str;
    getline(std::cin, str);
    int max_count = 0;
    int count = 0;
    std::string max_str;
    for (int i = 0; i < str.size() - 1; i++) {
        if (str[i] != ' ') {
            count++;
        } else {
            if (count > max_count) {
                max_str = str.substr(i - count, count);
                max_count = count;
            }
            count = 0;
        }
    }
    if (count > max_count) {
        max_str = str.substr(str.size() - 1 - count, count);
    }
    std::cout << max_str << std::endl;
    return 0;
}