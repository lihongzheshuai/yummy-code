#include <iostream>
#include <string>

int main() {
    long long a, b, c;
    std::cin >> a >> b >> c;

    std::string ans;
    if (a * a > b * c) {
        ans = "Alice";
    } else {
        ans = "Bob";
    }
    std::cout << ans;
    return 0;
}