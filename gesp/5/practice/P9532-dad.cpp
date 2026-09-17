#include <algorithm>  // 为了使用 std::max
#include <cmath>
#include <iostream>

// 题目分析：
// 数组性质：a[1] = k (任意正整数)
// a[2] = a[1] = k
// a[3] = a[1] + a[2] = 2k
// a[4] = a[1] + a[2] + a[3] = 4k
// ...
// a[i] = 2^(i-2) * k, 对于 i >= 2
// a[n] = 2^(n-2) * k
//
// 我们已知 x 在数组中。
// 为了使 a[n] 最小，我们需要让 x 在数组中的位置尽可能靠后（即下标 i
// 尽可能大）。 如果 x = a[i]，则 k = x / 2^(i-2)。 这要求 x 必须能被 2^(i-2)
// 整除。 此时 a[n] = k * 2^(n-2) = (x / 2^(i-2)) * 2^(n-2) = x * 2^(n-i)。
//
// 显然，i 越大，a[n] 越小。
// i 的最大值受限于：
// 1. i <= n
// 2. 2^(i-2) 必须是 x 的因子

int main() {
    int T;
    std::cin >> T;
    while (T--) {
        int n, x;
        std::cin >> n >> x;

        // 特判 x=1 的情况
        // 如果 x=1，由于所有数字都是正整数，k 只能为 1。
        // 序列只能是 1, 1, 2, 4...
        // a[n] = 1 * 2^(n-2)
        if (x == 1) {
            // pow 返回 double，对于大数可能丢失精度，但在题目范围内 (2^18)
            // 是安全的。 更严谨的写法是使用位运算：(1LL << (n - 2))
            std::cout << (long long)std::pow(2, n - 2) << std::endl;
            continue;
        }

        // 特判 n <= 2 的情况
        // 如果 n=1，a[1]=x。
        // 如果 n=2，a[2]=x (因为 a[2]=a[1]，若 x 在数组中，最小 a[2] 就是 x)。
        if (n <= 2) {
            std::cout << x << std::endl;
            continue;
        }

        // 计算 x 中包含多少个因子 2，记为 cnt。
        // 同时将 x 除以这些因子 2，剩下的 x 即为 k 的奇数部分 (odd_part)。
        int cnt = 0;
        while (x % 2 == 0) {
            cnt++;
            x /= 2;
        }

        // 此时 x 已经是 odd_part。
        // 我们需要计算最终结果 a[n] = 2^power * odd_part。
        //
        // 逻辑如下：
        // x_orig = odd_part * 2^cnt
        //
        // 情况 A: cnt >= n - 2
        // 这意味着 x_orig 包含的 2 的因子足够多，可以作为 a[n] (或者理论上的
        // a[n+1]...)。 但数组只有 n 项，所以 x_orig 最优就是作为 a[n]。 此时
        // a[n] = x_orig。 公式推导：power = cnt。 result = 2^cnt * odd_part =
        // x_orig。
        //
        // 情况 B: cnt < n - 2
        // 这意味着 x_orig 最多只能作为 a[cnt+2] (因为再往后需要更多的 2 因子)。
        // 此时 a[n] = a[cnt+2] * 2^(n - (cnt+2)) = x_orig * 2^(n - cnt - 2)。
        // 公式推导：power = n - 2。 result = 2^(n-2) * odd_part = 2^(n-2) *
        // (x_orig / 2^cnt) = x_orig * 2^(n-cnt-2)。
        //
        // 综上，power 取 max(cnt, n-2)。
        int power = std::max(cnt, n - 2);

        // 输出结果
        // 使用 long long 防止溢出
        std::cout << (long long)std::pow(2, power) * x << std::endl;
    }
    return 0;
}