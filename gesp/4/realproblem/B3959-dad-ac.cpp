#include <algorithm>
#include <iostream>


int ary[1000005];
int main() {
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> ary[i];
    }
    std::sort(ary, ary + n);
    int days = 0;
    for (int i = 0; i < n; i++) {
        if (ary[i] >= days + 1) {
            days++;
        }
    }
    std::cout << days;
    return 0;
}