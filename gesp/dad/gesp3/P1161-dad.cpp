#include <iostream>

int array[2000005];
int main() {
    int n;
    std::cin >> n;
    for (int i=0; i < n; i++) {
        double a;
        int t;
        std::cin >> a >> t;
        for (int j = 1; j <=t; j++) {
            int idx = a * j;
            array[idx] ^= 1;
        }

    }
    for (int i=0; i < 2000005; i++) {
        if (array[i] == 1) {
            std::cout << i << " ";
        }
    }
    return 0;
}