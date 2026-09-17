/*
 * P2696 慈善的约瑟夫
 * 题目链接：https://www.luogu.com.cn/problem/P2696
 *
 * 核心思路：
 * 1. 每一轮游戏是 K=2 的约瑟夫问题变种。
 * 2. 幸存者编号公式：J(n) = 2 * (n - 2^m) + 1，其中 2^m <= n。
 * 3. 每一轮比幸存者编号大的人离开，离开的人每人得 1 金币。
 * 4. 剩下的人数变为幸存者编号，继续下一轮。
 * 5. 当人数不再减少时，游戏结束，剩下的人每人得 2 金币。
 */
#include <iostream>

// 计算 N 个人每隔 1 人踢出 1 人后的幸存者编号 (K=2)
// 公式: J(n) = 2 * (n - 2^m) + 1, 其中 l = 2^m 是不超过 n 的最大 2 的幂
int get_survivor(int n) {
    if (n == 1) {
        return 1;
    }
    int l = 1;
    while (2 * l <= n) {
        l *= 2;
    }
    return 2 * (n - l) + 1;
}

int main() {
    int n;
    std::cin >> n;

    // 总金币数，累加项，使用 long long 防止溢出
    long long total = 0;

    while (true) {
        // Step 1: 计算当前人数 n 下的幸存者编号
        int survivor = get_survivor(n);

        // Step 2: 规则是“比幸存者号码高的人离开”
        // 即编号为 survivor+1 到 n 的人离开
        int leave_count = n - survivor;

        // 如果没有人离开（即所有人都留下了），循环结束
        if (leave_count == 0) {
            break;
        }

        // Step 3: 离开的人每人得到 1 个金币
        total += leave_count;

        // Step 4: 更新剩下的人数（剩下 survivor 个人）
        n = survivor;
    }

    // 最后剩下的人每人得到 2 个金币
    total += n * 2;

    std::cout << total << std::endl;
    return 0;
}