#include <iostream>
#include <vector>

int is_primes[1000005];
std::vector<int> prime_nums;

int main() {
    int n;
    std::cin >> n;
    is_primes[0] = is_primes[1] = 1;

    for (int i = 2; i <= 1000000; i++) {
        if (is_primes[i] == 0) {
            prime_nums.push_back(i);
        }
        for (int num : prime_nums) {
            long long x = 1LL * i * num;
            if (x > 1000000) {
                break;
            }
            is_primes[x] = 1;
            if (i % num == 0) {
                break;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        int a;
        std::cin >> a;
        int count = 0;
        for (int j = 0; j < prime_nums.size(); j++) {
            if (a % prime_nums[j] == 0) {
                count++;
            }
            if (count > 2) {
                break;
            }
        }
        std::cout << (count == 2 ? 1 : 0) << std::endl;
    }

    return 0;
}