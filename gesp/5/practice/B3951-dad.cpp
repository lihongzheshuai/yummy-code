#include <iostream>
#include <algorithm>

int nums[2005];
int sort_nums[2005];
int get_counts(int target_idx) {
    int count = 0;
    if (target_idx == 0) {
        return 0;
    }
    for (int i = target_idx - 1; i >= 0; i--) {
        if (sort_nums[target_idx] < sort_nums[i] && (i == 0 || sort_nums[i] != sort_nums[i - 1])) {
            count++;
            std::swap(sort_nums[target_idx], sort_nums[i]);
            target_idx = i;
        }
    }
    return count;
}

int main() {
    int N;
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::cin >> nums[i];
    }
    int M;
    std::cin >> M;
    for (int i = 0; i < M; i++) {
        int s_num;
        std::cin >> s_num;
        sort_nums[i] = nums[s_num];
        int count = get_counts(i);
        std::cout << count << std::endl;
    }
    return 0;
}