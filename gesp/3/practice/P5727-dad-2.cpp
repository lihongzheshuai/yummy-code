#include <iostream>
#include <vector>

std::vector<int> ary;
int main() {
    int n;
    std::cin >> n;
    ary.push_back(n);
    while (n != 1) {
        if (n % 2 == 0) {
            n /= 2;
        } else {
            n = n * 3 + 1;
        }
        ary.push_back(n);
    }
    for (int i = ary.size() - 1; i >= 0; i--) {
        std::cout << ary[i] << " ";
    }
    return 0;
}