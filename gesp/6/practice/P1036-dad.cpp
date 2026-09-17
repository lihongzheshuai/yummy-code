#include <cmath>
#include <iostream>

// 全局变量定义
int n, k;     // n: 整数个数, k: 选取的整数个数
int x[30];    // 存储n个整数，题目范围n<=20，开30足够
int ans = 0;  // 记录合法的组合方案数

/**
 * @brief 判断一个数是否为素数
 *
 * @param num 待判断的整数
 * @return true 如果num是素数
 * @return false 如果num不是素数
 */
bool isPrime(int num) {
    if (num < 2) return false;  // 小于2的数不是素数
    // 从2遍历到sqrt(num)，如果能整除则不是素数
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

/**
 * @brief 深度优先搜索（DFS）寻找组合
 *
 * @param index
 * 当前考虑的数字在数组中的作为起始下标（为了去重，保证组合选取的顺序）
 * @param count 当前已经选取的数字个数
 * @param sum 当前已经选取的数字之和
 */
void dfs(int index, int count, int sum) {
    // 递归出口：如果已经选够了k个数
    if (count == k) {
        // 判断当前和是否为素数
        if (isPrime(sum)) {
            ans++;  // 如果是素数，方案数加1
        }
        return;
    }

    // 剪枝：如果剩下的数字不足以凑齐k个，就不用继续了
    // 当前还需要选 k - count 个
    // 剩下能选的数字是从 index 到 n (下标1-based的话是 index 到 n)
    // 这里我们简单遍历即可，因为n很小。
    // 为了避免重复选取（例如选了 3, 7 和 7, 3 是同一种组合），我们每次只往后选

    for (int i = index; i <= n; i++) {
        // 选取第i个数，递归下一层
        // 下一层从 i + 1 开始选，已选个数+1，和加上x[i]
        dfs(i + 1, count + 1, sum + x[i]);
    }
}

int main() {
    // 优化输入输出
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    // 输入 n 和 k
    std::cin >> n >> k;

    // 输入 n 个整数
    for (int i = 1; i <= n; i++) {
        std::cin >> x[i];
    }

    // 从第1个数开始选，当前已选0个，当前和为0
    dfs(1, 0, 0);

    // 输出最终方案数
    std::cout << ans << std::endl;

    return 0;
}