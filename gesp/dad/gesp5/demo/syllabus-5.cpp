#include <vector>
#include <iostream>
using namespace std;

// 设置筛选范围的上限，根据n的范围调整
const int MAXN = 1000000;
// 存储找到的素数
vector<int> primes;
// 标记数组，初始假设所有数都是素数
vector<bool> is_prime(MAXN + 1, true);

/**
 * 线性筛法求素数
 * @param n 筛选范围上限
 */
void linear_sieve(int n) {
    // 0和1不是素数，标记为false
    is_prime[0] = is_prime[1] = false;
    // 从2开始遍历到n
    for (int i = 2; i <= n; i++) {
        // 如果i是素数，加入素数数组
        if (is_prime[i]) {
            primes.push_back(i);
        }
        // 用已知的素数去筛合数
        for (int p : primes) {
            // 计算i和素数p的乘积，用long long避免溢出
            long long x = 1LL * i * p;
            // 如果超出范围则退出当前循环
            if (x > n) {
                break;
            }
            // 标记i*p为合数
            is_prime[x] = false;
            // 如果i能被p整除，说明p是i的最小质因子，退出循环
            // 这样保证每个合数只会被其最小质因子筛掉一次
            if (i % p == 0) {
                break;  // 保证唯一筛标记
            }
        }
    }
}

int main() {
    int n = 30;
    linear_sieve(n);
    for (int i = 0; i < primes.size(); i++) {
        cout << primes[i] << " ";
    }
    return 0;
}