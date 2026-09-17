#include <iostream>
#include <map>

int main() {
    long long n;
    std::cin >> n;
    std::map<long long, int> factor_mp;
    for (long long i = 2; i * i <= n; i++) {
        int times = 0;
        while (n % i == 0) {
            times++;
            n /= i;
        }
        if (times > 0) {
            factor_mp.insert({i, times});
        }
    }
    if (n > 1) {
        factor_mp.insert({n, 1});
    }
    int count = 0;
    for (auto &f : factor_mp) {
        int total_times = f.second;
        for (int i = 1; i <= total_times; i++) {
            count++;
            total_times -= i;
        }
    }
    std::cout << count;

    return 0;
}
