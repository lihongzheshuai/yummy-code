#include <algorithm>
#include <iostream>

int ary[200005];
int main() {
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> ary[i];
    }
    std::sort(ary, ary + n);
    int count_diff = 1;
    int big_one = ary[n - 1];
    int big_two = 0, big_thr = 0;
    for (int i = n - 2; i >= 0; i--) {
        if (count_diff == 3) {
            break;
        }
        if (count_diff == 1 && ary[i] != big_one) {
            count_diff++;
            big_two = ary[i];
        }
        if (count_diff == 2 && ary[i] != big_two) {
            count_diff++;
            big_thr = ary[i];
        }
    }
    if (count_diff == 1) {
        std::cout << -1;
    } else if (count_diff == 2) {
        std::cout << big_one % big_two;
    } else {
        std::cout << std::max(big_thr, big_one % big_two);
    }
    return 0;
}