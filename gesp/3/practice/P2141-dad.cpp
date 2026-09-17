#include <iostream>

int array[105] = {0};
int r_array[20005] = {0};
int main() {
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> array[i];
        r_array[array[i]] = 1;
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (r_array[array[i] + array[j]]) {
                count++;
                r_array[array[i] + array[j]] = 0;
            }
        }
    }
    std::cout << count;
    return 0;
}