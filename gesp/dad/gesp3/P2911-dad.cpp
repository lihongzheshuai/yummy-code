#include <iostream>

int result[100] = {0};
int main () {

    int s1, s2, s3;
    std::cin >> s1 >> s2 >> s3;

    for (int i = 1; i <= s1; i++) {
        for (int j = 1; j <= s2; j++) {
            for (int k = 1; k <= s3;k++) {
                result[i + j + k]++;
            }
        }
    }

    int max = 0;
    int max_idx = 0;
    for (int i = 0; i <= s1 + s2 + s3; i++) {
        if (result[i] > max) {
            max = result[i];
            max_idx = i;
        }
    }
    std::cout << max_idx;
    return 0;
}