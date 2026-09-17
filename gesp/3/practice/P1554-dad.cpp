#include <iostream>

int main() {
    int m, n;
    std::cin >> m >> n;
    int result[10] = {0};
    for (int i = m; i <= n; i++) {
        std::string s = std::to_string(i);
        for (int j = 0; j < s.length(); j++) {
            result[s[j] - '0']++;
        }
    }
    for (int i = 0; i < 10; i++) {
        std::cout << result[i] << " ";
    }
    return 0;
}