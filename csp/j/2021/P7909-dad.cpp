#include <iostream>

int main() {
    int n, L, R;
    std::cin >> n >> L >> R;

    int ans;
    int sub = R - L;
    if (sub >= n) {
        ans = n - 1;
    } else {
        int l_mod = L % n;
        int l_mod_sum = l_mod + sub;
        if (l_mod_sum >= n) {
            ans = n - 1;
        } else {
            ans = l_mod_sum;
        }
    }
    std::cout << ans;

    return 0;
}