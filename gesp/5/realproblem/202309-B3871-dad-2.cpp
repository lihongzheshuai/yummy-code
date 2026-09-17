#include <vector>
#include <iostream>
#include <cmath>

int main() {
    long long N;
    std::cin >> N;
    std::vector<std::pair<long long, int>> factors;
    for (long long i = 2; i <= std::sqrt(N); i++) {
        if (N % i == 0) { 
            int count = 0;
            while (N % i == 0) {
                count++;
                N /= i;
            }
            factors.push_back({i, count});
        }
    }
    if (N > 1) {
        factors.push_back({N, 1});
    }
    for (size_t i = 0 ; i < factors.size(); i++) {
        if (i > 0) {
            std::cout << " * ";
        }
        std::cout << factors[i].first;
        if (factors[i].second > 1) {
            std::cout << "^" << factors[i].second;
        }
    }
    return 0;
}