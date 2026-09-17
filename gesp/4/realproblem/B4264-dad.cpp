#include <iostream>

int num_ary[505][505];
int main() {
    int n, m;
    std::cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> num_ary[i][j];
        }
    }
    int count = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m - 1; j++) {
            if (num_ary[i][j] * num_ary[i+1][j+1] == num_ary[i][j+1] * num_ary[i+1][j]) {
                count++;
            }
        }
    }
    std::cout << count;
    return 0;
}