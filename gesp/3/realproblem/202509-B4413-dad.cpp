#include <iostream>

int num_ary[105];
int main() {
    int n;
    std::cin >> n;
    int count = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> num_ary[i];
    }
    bool flag = false;
    while (true) {
        flag = true;
        int min = 101;
        int max = 0;
        int max_idx = -1;
        for (int i = 0; i < n; i++) {
            if (num_ary[i] != 0) {
                flag = false;
            } else {
                continue;
            }
            if (num_ary[i] < min && num_ary[i] != 0) {
                min = num_ary[i];
            }
            if (num_ary[i] >= max) {
                max = num_ary[i];
                max_idx = i;
            }
        }
        if (flag) {
            break;
        }
        num_ary[max_idx] -= min;
        count++;
    }

    std::cout << count << std::endl;
    return 0;
}