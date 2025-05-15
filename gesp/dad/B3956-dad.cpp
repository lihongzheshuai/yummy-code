#include <iostream>
#include <string>

int main() {
    int n;
    std::cin >> n;
    std::string pwd;
    std::cin >> pwd;
    int result = 0;
    for (int i = 0; i < pwd.length(); i++) {
        if (std::islower(pwd[i])) {
            result += pwd[i] - 'a' + 1;
        } else {
            result += pwd[i] * -1;
        }
    }
    std::cout << result;
    return 0;
}