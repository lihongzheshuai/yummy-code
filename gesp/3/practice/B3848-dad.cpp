#include <iostream>

int main() {
    int n;
    std::cin >> n;
    int ary[n];
    for (int i = 0; i < n; i++) {
        std::cin >> ary[i];
    }
    int money;
    std::cin >> money;
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (money >= ary[i]) {
            count++;
            money -= ary[i];
        }
    }
    std::cout << count;
    return 0;
}