#include <iostream>

int nums[2005];

int get_counts(int s_size, int times) {
    int count = 0;
    for (int i = 0; i < times; i++) {
        for (int j = i + 1; j < times; j++) {
            if (nums[i] > nums[j]) {
                count++;
            }
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
        int times;
        std::cin >> times;
        int count = get_counts(N, times);
        std::cout << "count: " << count << std::endl;
    }
    return 0;

}