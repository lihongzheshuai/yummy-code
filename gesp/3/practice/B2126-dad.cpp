#include <iostream>
#include <string>

int main() {
    int k;
    std::cin >> k;
    std::string str;
    std::cin >> str;
    int count = 1;
    char cur_c = str[0];
    for (int i = 1; i < str.length(); i++) {
        if (str[i] == cur_c) {
            count++;
        } else {
            cur_c = str[i];
            count = 1;
        }
        if (count >= k) {
            std::cout << cur_c << std::endl;
            return 0;
        }
    }
    std::cout << "No";
    return 0;
}