#include <cmath>
#include <iostream>

int main() {
    long long N;
    std::cin >> N;
    bool flag = false;

    for (long long i = 2; i <= std::sqrt(N); i++) {
        if (N % i == 0) { 
            int count = 0;
            while (N % i == 0) {
                count++;
                N /= i;
            }
            if (flag) {
                std::cout << " * ";
            }
            flag = true;
            std::cout << i;
            if (count > 1) {
                std::cout << "^" << count;
            }
        }
    }
    if (N > 1) {
        if (flag) {
            std::cout << " * ";
        }
        std::cout << N;
    }
    return 0;
}