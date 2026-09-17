#include <iostream>

int result[40][40];
int main() {
    int N;
    std::cin >> N;
    result[0][(N - 1) / 2] = 1;
    int last_i = 0;
    int last_j = (N - 1) / 2;
    for (int i = 2; i <= N * N; i++) {
        if (last_i == 0 && last_j != N - 1) {
            last_i = N - 1;
            last_j = last_j + 1;
            result[last_i][last_j] = i;
        } else if (last_i != 0 && last_j == N - 1) {
            last_i = last_i - 1;
            last_j = 0;
            result[last_i][last_j] = i;
        } else if (last_i == 0 && last_j == N -1) {
            last_i += 1;
            last_j = N - 1;
            result[last_i][last_j] = i;
        } else {
            if (result[last_i - 1][last_j + 1] == 0) {
                last_i -= 1;
                last_j += 1;
                result[last_i][last_j] = i;
            } else {
                last_i += 1;
                result[last_i][last_j] = i;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << result[i][j] << " ";
        }
        std::cout << "\n";
    }
    return 0;
}