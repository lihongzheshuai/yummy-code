#include <iostream>
#include <string>

int main() {
    double level;
    std::string str_1, str_2;
    std::cin >> level >> str_1 >> str_2;
    int same_count = 0;
    for (int i = 0; i < str_1.size(); i++) {
        if (str_1[i] == str_2[i]) {
            same_count++;
        }
    }
    if ((double)same_count / str_1.size() >= level) {
        std::cout << "yes";
    } else {
        std::cout << "no";
    }
    return 0;
}
