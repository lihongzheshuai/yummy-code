/**
 * 题目: 【GESP真题】GESP五级 / CSP-J 题解：luogu-P17455 [GESP202609 五级] 哥德巴赫猜想
 * 题号: P17455
 * 归属: GESP5级 (202609认证真题)
 * 博客: https://www.coderli.com/gesp-5-luogu-p17455-goldbach/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

/**
 * Problem: luogu-P17455
 * Standard: C++11 (CCF GESP 官方大纲规范)
 * Author: OneCoder
 */

#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 1000000;
bool is_prime[MAXN + 1];
vector<int> primes;

// 欧拉线性筛：保证每个合数仅被其最小质因数筛掉一次
void sieve(int limit) {
    for (int i = 2; i <= limit; ++i) is_prime[i] = true;
    for (int i = 2; i <= limit; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
        for (int p : primes) {
            if (i * p > limit) break;
            is_prime[i * p] = false;
            if (i % p == 0) break;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n) || n <= 2 || n % 2 != 0) {
        return 0;
    }

    sieve(n);

    int count = 0;
    // 枚举较小质数 p <= n / 2，保证方案不重复
    for (int p : primes) {
        if (p > n / 2) break;
        int q = n - p;
        if (is_prime[q]) {
            count++;
        }
    }

    cout << count << "\n";

    return 0;
}
