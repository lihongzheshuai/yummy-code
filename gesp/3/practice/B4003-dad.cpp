#include <iostream>

int main() {
    int n;
    std::cin >> n;
    for (int i = 0; i < 26; i++) {
        int cur_idx = 'A' + i + n % 26;
        if (cur_idx > 'Z') {
            cur_idx -= 26;
        }
        std::cout << char(cur_idx);
    }
    return 0;
}