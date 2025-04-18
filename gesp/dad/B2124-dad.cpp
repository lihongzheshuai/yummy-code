#include <iostream>
#include <string>

int main() {
    std::string input;
    std::cin >> input;
    int begin = 0;
    int end = input.length() - 1;
    while (begin < end) {
        if (input[begin] != input[end]) {
            std::cout << "no";
            return 0;
        } else {
            begin++;
            end--;
        }
    }
    std::cout << "yes";
    return 0;
}