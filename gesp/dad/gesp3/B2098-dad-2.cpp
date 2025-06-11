#include <iostream>

int num_array[20005] = {};
int main() {
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        std::cin >> num;
        bool flag = true;
        for (int j = 0; j < i; j++) {
            if (num_array[j] == num) {
                flag = false;
                break;
            }
        }
        if (flag) {
            std::cout << num << " ";
            num_array[i] = num;
        }
    }
    return 0;
}