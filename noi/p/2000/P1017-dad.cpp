#include <iostream>

int main() {
    int n, R;
    std::cin >> n >> R;
    int absR = std::abs(R);
    int tmp = n;
    std::string ans;
    std::cout << -15 % -2 << '\n';
    std::cout << -15 % 2 << '\n';
    if (n == 0) {
        ans = "0";
    }
    while (tmp != 0) {
        int mod;
        if (tmp > 0)
            mod = tmp % absR;
        else
            int mod = tmp % absR + absR;
        tmp /= absR;
        ans += std::to_string(mod);
    }

    std::cout << n << "=" << ans << "(base" << R << ")";
}