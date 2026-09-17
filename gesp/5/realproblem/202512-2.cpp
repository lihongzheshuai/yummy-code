#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <vector>

/**
 * GESP 2025年12月 五级编程题 T2: 最小金币
 *
 * 题目描述：
 * 给定 N 个整数，每次可以将一个数乘以或除以一个质数 P（花费 1 金币）。
 * 求将所有数变为同一个数所需的最小金币数。
 *
 * 算法思路：
 * 1. 本质是求
 * "几何中位数"。在数论意义下，两个数之间的距离定义为它们质因数分解后，各质因子指数差的绝对值之和。
 *    例如 12 = 2^2 * 3^1, 18 = 2^1 * 3^2。
 *    距离 = |2-1| + |1-2| = 2。对应操作：12 / 2 * 3 = 18。
 * 2. 假设目标数为 T = p1^E1 * p2^E2 * ...
 *    总代价 = Σ distance(a_i, T) = Σ Σ |e_{i,j} - E_j|
 *    其中 e_{i,j} 是 a_i 分解中质因子 p_j 的指数。
 * 3. 要使总代价最小，可以对每个质因子 p_j 独立考虑。
 *    根据中位数性质，E_j 应该取所有 a_i 在该质因子上指数 e_{i,j} 的中位数。
 * 4. 步骤：
 *    a. 对每个数 a_i 进行质因数分解，记录所有出现的质因子及其指数。
 *       使用 map<int, vector<int>> 存储，key 是质数，value 是非零指数列表。
 *    b. 对于每个质因子 p：
 *       - 获取其所有非零指数，设个数为 k。
 *       - 补齐 N-k 个 0（表示其他 N-k 个数没有这个质因子）。
 *       - 找到这 N 个数的中位数。
 *       - 计算该质因子贡献的最小代价：Σ |指数 - 中位数|。
 *    c. 累加所有质因子的代价即为答案。
 */

using namespace std;

// 预处理质数，用于快速分解
const int MAX_SQRT = 32000;
vector<int> primes;
bool is_prime[MAX_SQRT + 5];

void sieve() {
    fill(is_prime, is_prime + MAX_SQRT + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= MAX_SQRT; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = i * i; j <= MAX_SQRT; j += i) is_prime[j] = false;
        }
    }
}

int main() {
    // 优化输入输出
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();

    int n;
    if (!(cin >> n)) return 0;

    // 存储每个质因子的所有非零指数
    map<int, vector<int>> prime_counts;

    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        // 质因数分解
        for (int p : primes) {
            if (p * p > val) break;
            if (val % p == 0) {
                int count = 0;
                while (val % p == 0) {
                    count++;
                    val /= p;
                }
                prime_counts[p].push_back(count);
            }
        }
        if (val > 1) {
            prime_counts[val].push_back(1);
        }
    }

    long long total_cost = 0;

    // 遍历每个出现过的质因子
    for (auto& pair : prime_counts) {
        vector<int>& counts = pair.second;
        // counts 中只存储了非零的指数，共有 k 个
        // 实际上总共有 N 个数，剩下的 N-k 个数的指数为 0
        int k = counts.size();

        // 我们需要找到这 N 个数的中位数
        // 排序非零指数
        sort(counts.begin(), counts.end());

        int median = 0;
        int zeros = n - k;  // 0 的个数

        // 中位数的位置是 N/2 (0-indexed)
        // 序列构成：[0, 0, ..., 0] (zeros个) + [counts[0], counts[1], ...]
        if (n / 2 < zeros) {
            // 中位数落在 0 的区域
            median = 0;
        } else {
            // 中位数落在 counts 的区域
            // counts 中的下标 = 总下标 - zeros
            median = counts[n / 2 - zeros];
        }

        // 计算代价
        // 1. 对于非零指数的部分
        for (int c : counts) {
            total_cost += abs(c - median);
        }
        // 2. 对于零指数的部分 (值为0，代价为 |0 - median| = median)
        total_cost += (long long)zeros * median;
    }

    cout << total_cost << endl;

    return 0;
}
