#include <iostream>
#include <string>
#include <cmath>

long long trans_to_decimal(const std::string& s, const int k) {
    long long decimal = 0;
    for (int i = s.length() - 1; i >= 0; i--) {
        if (s[i] >= '0' && s[i] <= '9') {
            decimal += (s[i] - '0') * std::pow(k, s.length() - i - 1);
        } else {
            decimal += (s[i] - 'A' + 10) * pow(k, s.length() - i - 1);
        }
    }
    return decimal;
}

int main() {

    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        int k;
        std::string s;
        std::cin >> k >> s;
        std::cout << trans_to_decimal(s, k) << "\n";
    }
    return 0;

}