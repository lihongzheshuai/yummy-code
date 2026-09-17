#include <iostream>

int main() {

    int n;
    std::cin >> n;
    int count = 0;
    for (int i = n; i > 0; i--) {
        count += i * i;
    }
    std::cout << count << std::endl;
    return 0;
}