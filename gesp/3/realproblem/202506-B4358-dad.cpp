#include <iostream>

int main() {
    int n;
    std::cin >> n;
    int count = 0;
    for (int i = 0; i < n; i++) {
        int c;
        std::cin >> c;
        while (c) {
            int bit = c % 2;
            if (bit == 1) {
                count++;
            }
            c /= 2;
        }
    }
    int y = count % 2 == 0 ? 0 : 1;
    std::cout << count << " " << y << std::endl;
    return 0;
}