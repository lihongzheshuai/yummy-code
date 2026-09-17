#include <iostream>
#include <array>

std::array<int, 10005> result_ary;
int main() {
    int l, m;
    std::cin >> l >> m;
    result_ary.fill(1);
    for (int i = 0; i < m; i++) {
        int a, b;
        std::cin >> a >> b;
        for (int j = a; j <= b; j++) {
            result_ary.at(j) = 0;
        }
    }
    int count = 0;
    for (int i = 0; i <= l; i++) {
        if (result_ary.at(i)) {
            count++;
        }
    }
    std::cout << count;
    return 0;
}                  