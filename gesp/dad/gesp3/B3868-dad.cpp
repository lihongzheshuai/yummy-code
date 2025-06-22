#include <iostream>
#include <string>

int main() {
    int n;
    std::cin >> n;
    int count = 0;
    for (int i = 0; i < n; i++) {
        std::string str;
        std::cin >> str;
        int result[4] = {1, 1, 1, 1};
        for (int j = 0; j < str.length(); j++) {
            if (str[j] > '1') {
                result[0] = 0;
            }
            if (str[j] > '7') {
                result[1] = 0;
            }
            if (str[j] > '9') {
                result[2] = 0;
            }
            if (str[j] > 'F') {
                result[3] = 0;
            }
        }
        for (int j = 0; j < 4; j++) {
            std::cout << result[j] << " ";
        }
        std::cout << "\n";
    }
    return 0;
}