#include <cctype>
#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string input;
    std::cin >> input;
    for (int i = 0; i < input.length(); i++) {
        if (std::islower(input[i])) {
            input[i] = std::toupper(input[i]);
        } else if (std::isupper(input[i])) {
            input[i] = std::tolower(input[i]);
        }
    }
    std::reverse(input.begin(), input.end());
    for (int i = 0; i < input.length(); i++) {
        if (input[i] == 'x') {
            input[i] = 'a';
        } else if (input[i] == 'y') {
            input[i] = 'b';
        } else if (input[i] == 'z') {
            input[i] = 'c';
        } else if (input[i] == 'X') {
            input[i] = 'A';
        } else if (input[i] == 'Y') {
            input[i] = 'B';
        } else if (input[i] == 'Z') {
            input[i] = 'C';
        } else {
            input[i] = input[i] + 3;
        }
    }
    std::cout << input;
    return 0;
}
