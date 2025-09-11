#include <iostream>
#include <algorithm>

int ary[3005];

bool is_exist(int num, int n) {
    for (int i = 1; i <= n; i++) {
        if (ary[i] == num) {
            return true;
        }
    }
    return false;
}

int main() {
    int n;
    std::cin >>n;
    ary[1] = 1;
    for (int i = 2; i <= n; i++) {
        int tmp_num = ary[i - 1] - i;
        if (tmp_num > 0 && !is_exist(tmp_num, i)) {
            ary[i] = tmp_num;
        } else {
            ary[i] = ary[i - 1] + i;
        }
        
    }
    std::sort(ary + 1, ary + n + 1);
    for (int i = 1; i <= n; i++) {
        std::cout << ary[i] << " ";
    }
    return 0;

}