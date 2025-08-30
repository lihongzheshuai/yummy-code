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
    int idx = 0;
    for (int i = 0; i < n; i++) {
        for (int j = idx; j < n; j++) {
            if (ary[j] >= i + 1) {
                days++;
                idx = j + 1;
                break;
            }
        }
    }
    std::cout << days;
    return 0;
}