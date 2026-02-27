#include <iostream>

void solve(int n) {
    bool first = true;
    for (int i = 14; i >= 0; i--) {
        if ((n >> i) & 1) {
            if (!first) {
                std::cout << "+";
            }
            first = false;
            if (i == 0) {
                std::cout << "2(0)";
            } else if (i == 1) {
                std::cout << "2";
            } else {
                std::cout << "2(";
                solve(i);
                std::cout << ")";
            }
        }
    }
}

int main() {
    int n;
    std::cin >> n;

    solve(n);
    return 0;
}