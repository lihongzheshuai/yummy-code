#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

// [优化建议]: 使用 long long 类型来累加答案，防止结果溢出 int 范围。
// 虽然本题 N=10^5，指数不大，答案可能在 int 范围内，但使用 long long 是好习惯。
typedef long long ll;

const int MAXN = 100005;
int a[MAXN];
// primes_ary 用于线性筛标记合数
int primes_ary[MAXN];
std::vector<int> primes;

// 记录每个质数在各数字中的指数列表。
// key: 质数 p (作为数组下标)
std::vector<int> factors[MAXN];

int main() {
    int N;
    std::cin >> N;

    for (int i = 1; i <= N; i++) {
        std::cin >> a[i];
    }

    // --- 1. 线性筛（欧拉筛）预处理质数 ---
    // 预处理 1 到 100005 之间的所有质数
    primes_ary[1] = 1;  // 1 不是质数
    for (int i = 2; i < MAXN; i++) {
        if (primes_ary[i] == 0) {
            primes.push_back(i);
        }
        // 遍历已有的质数，标记合数
        for (int j = 0; j < primes.size(); j++) {
            // 如果超出范围则停止
            if ((ll)primes[j] * i >= MAXN) {
                break;
            }
            primes_ary[primes[j] * i] = 1;

            // 欧拉筛的核心：如果 i 是 prime[j] 的倍数，说明 i
            // 已经被更小的质因子筛过了
            // 此时停止，保证每个合数只被其最小质因子筛一次，达到 O(N) 复杂度。
            if (i % primes[j] == 0) {
                break;
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        int tmp = a[i];

        // 分解质因数
        for (int p : primes) {
            // 如果 p*p > tmp，说明剩下的 tmp 要么是 1，要么是一个大于
            // sqrt(a[i]) 的质数。
            // 这样可以提前退出循环，避免无效遍历，显著降低复杂度。
            if (1LL * p * p > tmp) {
                break;
            }

            if (tmp % p == 0) {
                int exponent = 0;
                while (tmp % p == 0) {
                    tmp /= p;
                    exponent++;
                }
                // 将质因数 p 的指数 exponent（即p出现的字数） 存入对应的 vector
                // 中
                factors[p].push_back(exponent);
            }
        }
        // 处理最后剩下的那个较大的质因子
        if (tmp > 1) {
            factors[tmp].push_back(1);
        }
    }

    ll ans = 0;

    // --- 3. 计算最小代价 ---
    // 遍历每一个出现过的质因数
    for (int p : primes) {
        std::vector<int> exps = factors[p];

        // 3.1 对非零指数进行排序
        std::sort(exps.begin(), exps.end());

        // 3.2 确定中位数
        // 序列总长度应为 N（包含 exps 中的非零值和 (N - exps.size()) 个 0）
        // 逻辑上的完整列表可以看作： [0, 0, ..., 0, exps[0], exps[1], ...]
        int num_zeros = N - exps.size();
        int mid_idx = N / 2;  // 中位数在逻辑列表中的下标（0-indexed）

        int median = 0;
        if (mid_idx >= num_zeros) {
            // 如果中位数下标落在了非零部分（即 exps 数组中）
            // 对应的 exps 下标为 mid_idx - num_zeros
            median = exps[mid_idx - num_zeros];
        } else {
            // 如果中位数下标落在 0 的区域
            median = 0;
        }

        // 3.3 计算由于该质因数产生的代价
        // 代价 = sum(|x - median|)

        // (1) 那些值为 0 的数贡献的代价： |0 - median| * num_zeros = median *
        // num_zeros
        ll cost = (ll)median * num_zeros;

        // (2) 那些非零的数贡献的代价
        for (int e : exps) {
            cost += std::abs(e - median);
        }

        ans += cost;
    }

    std::cout << ans << '\n';
    return 0;
}