#include <iostream>
#include <string>

int main() {
    std::string str;
    std::getline(std::cin, str);
    int length = str.length();
    int max_length = 0;
    int min_length = 100;
    std::string str_max, str_min;
    int count = 0;
    for (int i = 0; i < length; i++) {
        if (str[i] == ' ' || str[i] == ',' || str[i] == '.') {
            if (count == 0) {
                continue;
            }
            if (count > max_length) {
                max_length = count;
                str_max = str.substr(i - count, count);
            }
            if (count < min_length) {
                min_length = count;
                str_min = str.substr(i - count, count);
            }
            count = 0;
        } else if (i == length - 1) {
            count++;
            if (count > max_length) {
                max_length = count;
                str_max = str.substr(i - count + 1, count);
            }
            if (count < min_length) {
                min_length = count;
                str_min = str.substr(i - count + 1, count);
            }
        } else {
            count++;
        }
    }
    std::cout << str_max << std::endl;
    std::cout << str_min << std::endl;
    return 0;
}