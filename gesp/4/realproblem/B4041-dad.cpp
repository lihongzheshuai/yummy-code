#include <iostream>
#include <algorithm>

int num_ary[105];
int main() {
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> num_ary[i];
    }
    int q;
    std::cin >> q;
    for (int i = 0; i < q; i++) {
        int l, r;
        std::cin >> l >> r;
        std::sort(num_ary + l - 1, num_ary + r);
    }
    for (int i = 0; i < n; i++) {
        std::cout << num_ary[i] << " ";
    }
    return 0;
}