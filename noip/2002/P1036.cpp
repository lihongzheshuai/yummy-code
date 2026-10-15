/**
 * Problem: luogu-P1036 [NOIP2002 普及组] 选数
 * Algorithm: 递归枚举组合与试除法质数判定 (Recursive Combination Enumeration & Primality Test)
 * Standard: C++11 (CCF GESP 四级 / CSP-J 官方规范)
 * Author: OneCoder
 */

#include <iostream>

using namespace std;

int n, k;
int x[25];    // 存储读入的 n 个整数
int ans = 0;  // 统计和为质数的组合方案总数

/**
 * 试除法判断正整数 num 是否为质数（素数）
 * @param num 待判断的整数
 * @return 若为质数返回 true，否则返回 false
 */
bool is_prime(int num) {
    // 小于 2 的整数均不是质数
    if (num < 2) {
        return false;
    }
    // 枚举从 2 到 sqrt(num) 的所有整数测试能否整除
    // 使用 i * i <= num 避免调用浮点函数 sqrt() 带来的精度问题
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            return false; // 存在除了 1 和自身以外的约数，是合数
        }
    }
    return true;
}

/**
 * 递归枚举从 n 个数中选出 k 个数的所有组合
 * @param step  当前正在选择第几个数（从 1 到 k）
 * @param start 当前允许从数组 x 的哪个下标开始往后选择（保证下标严格递增，不重复选）
 * @param sum   当前已经选出的数字累加和
 */
void dfs(int step, int start, int sum) {
    // 递归边界：当 step > k 时，说明已经选满了 k 个数字
    if (step > k) {
        // 检查这 k 个数字的累加和是否为质数
        if (is_prime(sum)) {
            ans++;
        }
        return;
    }

    // 枚举当前第 step 个位置选择的数组下标 i
    // 可行性剪枝：剩余可选元素的数量 (n - i) 必须不少于还需选择的个数 (k - step)
    // 即 n - i >= k - step，移项可得 i <= n - (k - step)
    for (int i = start; i <= n - (k - step); ++i) {
        // 选中 x[i]，继续递归选择第 step + 1 个数，下一层起始下标为 i + 1，累加和加上 x[i]
        dfs(step + 1, i + 1, sum + x[i]);
    }
}

int main() {
    // 读取整数总数 n 和需要选取的个数 k
    cin >> n >> k;

    // 读取 n 个整数（下标从 1 到 n 存储）
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
    }

    // 从第 1 个选位、数组起始下标 1、初始累加和 0 开始深度优先搜索
    dfs(1, 1, 0);

    // 输出和为素数的种类总数
    cout << ans << "\n";

    return 0;
}
