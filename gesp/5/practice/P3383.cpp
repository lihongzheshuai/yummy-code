/**
 * Problem: luogu-P3383 【模板】线性筛素数
 * Algorithm: 初等数论·欧拉线性筛法 (Euler's Linear Sieve)
 * Standard: C++11 (CCF GESP 五级 / CSP-J 官方规范)
 * Blog: https://www.coderli.com/gesp-5-luogu-p3383/
 * Author: OneCoder
 */

#include <iostream>

using namespace std;

// 查询范围最大为 10^8，10^8 以内共有 5,761,455 个质数
// 大规模数组必须声明在全局静态存储区（BSS 段），严禁放在 main 函数栈空间内以防爆栈（MLE/RE）
const int MAXN = 100000005;
const int MAXP = 6000005;

// is_comp[x] 为 true 表示 x 是合数（已被筛除），为 false 表示 x 是质数
bool is_comp[MAXN];

// primes[k] 按从小到大的顺序存储第 k 小的质数（下标从 1 开始）
int primes[MAXP];

// 已筛出的质数总个数
int cnt = 0;

/**
 * 欧拉线性筛（Euler's Sieve）预处理 [2, n] 范围内的所有质数
 * 核心性质：每个合数仅被其“最小质因数”唯一筛除一次，时间复杂度严格为 O(n)
 * @param n 筛法处理的正整数上限
 */
void euler_sieve(int n) {
    // 0 和 1 既不是质数也不是合数，预先标记为非质数
    is_comp[0] = true;
    is_comp[1] = true;

    for (int i = 2; i <= n; ++i) {
        // 如果 i 未被任何更小的数筛除，说明 i 必然是质数，收入质数表
        if (!is_comp[i]) {
            primes[++cnt] = i;
        }

        // 遍历当前已筛出的所有质数 primes[j]，用 i * primes[j] 筛除合数
        // 使用 1LL * i * primes[j] <= n 防止乘积超出 32 位有符号整型上限导致溢出
        for (int j = 1; j <= cnt && 1LL * i * primes[j] <= n; ++j) {
            // 将合数 i * primes[j] 标记为已筛除，此时 primes[j] 是它的最小质因数
            is_comp[i * primes[j]] = true;

            // 【欧拉筛灵魂剪枝】
            // 若 primes[j] 整除 i，说明 i 本身已经包含质因子 primes[j]（即 i 的最小质因数就是 primes[j]）。
            // 如果继续向后枚举更大的质数 primes[j+1]，那么合数 M = i * primes[j+1] 的最小质因数依然是 primes[j] 而非 primes[j+1]，
            // M 会在后续外层循环枚举到 i' = (i / primes[j]) * primes[j+1] 时被 primes[j] 正常筛除。
            // 因此必须立即 break 终止内层循环，确保每个合数绝不被重复标记！
            if (i % primes[j] == 0) {
                break;
            }
        }
    }
}

int main() {
    // 读取查询范围上限 n 和询问个数 q
    int n, q;
    cin >> n >> q;

    // 线性时间 O(n) 预处理 1 ~ n 范围内的全部质数
    euler_sieve(n);

    // 依次回答 q 次查询，每次 O(1) 查表输出第 k 小的质数
    for (int i = 0; i < q; ++i) {
        int k;
        cin >> k;
        cout << primes[k] << "\n";
    }

    return 0;
}
