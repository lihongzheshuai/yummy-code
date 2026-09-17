#include <cmath>
#include <iostream>

int count_ary[100005] = {};
int main() {
    int n;
    std::cin >> n;
    int max_num = -1;
    for (int i = 0; i < n; i++) {
        int cur_num;
        std::cin >> cur_num;
        max_num = std::max(max_num, cur_num);
        count_ary[cur_num]++;
    }
    for (int i = 0; i <= max_num; i++) {
        std::cout << count_ary[i] << "\n";
    }
    return 0;
}