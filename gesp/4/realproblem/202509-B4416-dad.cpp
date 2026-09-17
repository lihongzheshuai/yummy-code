#include <algorithm>
#include <iostream>


const int MAX_N = 1 * 10e5 + 5;
int num_ary[MAX_N];
int main() {
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> num_ary[i];
    }
    std::sort(num_ary, num_ary + n);
    int max_count = 0;
    int count = 1;
    int idx = 0;
    for (int i = idx; i < n; i++) {
        if (num_ary[i + 1] == num_ary[i]) {
            idx++;
            continue;
        } else if (num_ary[i + 1] == num_ary[i] + 1) {
            count++;
            idx++;
        } else {
            max_count = std::max(max_count, count);
            count = 1;
            idx = i + 1;
        }
    }
    std::cout << max_count << std::endl;
    return 0;
}