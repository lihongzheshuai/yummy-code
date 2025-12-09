#include <cmath>
#include <iostream>

int current_sum[100005];
int first_pos[200005];
const int OFFSET = 100000;
int main() {
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        int num;
        std::cin >> num;
        if (num == 0) {
            num = -1;
        }
        current_sum[i] = current_sum[i - 1] + num;
    }
    int max_len = 0;
    std::fill(first_pos, first_pos + 200005, -1);
    first_pos[OFFSET] = 0;
    for (int i = 1; i <= n; i++) {
        if (first_pos[current_sum[i] + OFFSET] == -1) {
            first_pos[current_sum[i] + OFFSET] = i;
        } else {
            max_len = std::max(max_len, i - first_pos[current_sum[i] + OFFSET]);
        }
    }

    std::cout << max_len << std::endl;
    return 0;
}