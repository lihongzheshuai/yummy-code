#include <algorithm>
#include <iostream>
#include <map>

std::string str_ary[105];
bool check(int n) {
    for (int i = 1; i < n; i++) {
        if (str_ary[i - 1].back() > str_ary[i].front()) {
            return false;
        }
    }
    return true;
}
int main() {
    int T;
    std::cin >> T;
    while (T--) {
        int n;
        std::cin >> n;
        bool flag = true;
        for (int i = 0; i < n; i++) {
            std::cin >> str_ary[i];
            if (!is_sorted(str_ary[i].begin(), str_ary[i].end())) {
                flag = false;
            }
        }
        std::sort(str_ary, str_ary + n);
        if (flag && check(n)) {
            std::cout << "1" << "\n";
        } else {
            std::cout << "0" << "\n";
        }
    }

    return 0;
}