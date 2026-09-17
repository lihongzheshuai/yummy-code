/**
 * 题目: 【GESP】C++五级真题（数论, 贪心思想考点） luogu-B4070 [GESP202412 五级] 奇妙数字
 * 题号: B4070
 * 归属: GESP5级 (202412认证真题)
 * 博客: https://www.coderli.com/gesp-5-luogu-b4070/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <map>

int main() {
    long long n;                       // 读入待分解的正整数 n（2 ≤ n ≤ 1e12）
    std::cin >> n;
    std::map<long long, int> factor_mp; // 用 map 存储质因子及其出现次数（自动按质数升序）
    // 试除法：从小到大枚举可能的质因子 i
    for (long long i = 2; i * i <= n; i++) {
        int times = 0;                 // 统计当前质数 i 的幂次
        while (n % i == 0) {             // 能整除就继续除
            times++;
            n /= i;
        }
        if (times > 0) {                 // 若 i 确实是质因子，记录
            factor_mp.insert({i, times});
        }
    }
    // 若剩余 n > 1，则它本身是一个大于 sqrt(原 n) 的质因子
    if (n > 1) {
        factor_mp.insert({n, 1});
    }

    int count = 0;                       // 统计最多能选出的“奇妙数字”个数
    // 对每个质因子 p^e，我们要把它拆成尽可能多的互不相同的 p^k 形式
    // 贪心策略：依次选 p^1, p^2, p^3…，直到把 e 用完
    for (auto &f : factor_mp) {
        int total_times = f.second;      // 该质数的总幂次
        for (int i = 1; i <= total_times; i++) {
            count++;                     // 选了一个 p^i
            total_times -= i;            // 消耗掉 i 次幂
        }
    }
    std::cout << count;                // 输出最多能选出的奇妙数字个数

    return 0;
}
