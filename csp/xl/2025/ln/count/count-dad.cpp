#include <iostream>

int count_ary[26] = {};
int main() {
    freopen("count.in", "r", stdin);
    freopen("count.out", "w", stdout);
    std::string str;
    std::cin >> str;
    for (int i = 0; i < str.length(); i++) {
        count_ary[str[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
        std::cout << count_ary[i] << "\n";
    }
    return 0;
}