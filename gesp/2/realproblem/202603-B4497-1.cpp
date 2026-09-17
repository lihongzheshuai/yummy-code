/**
 * 题目: 【GESP】C++二级真题 luogu-B4497, [GESP202603 二级] 数数
 * 题号: B4497
 * 归属: GESP2级 (202603认证真题)
 * 解法: 解法 1 / 共 2 种解法
 * 博客: https://www.coderli.com/gesp-2-luogu-b4497/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>

int main() {
    // 1. 读入范围起点 L 和终点 R
    int L, R;
    std::cin >> L >> R;

    // 2. 准备用于记录符合条件的"美丽数"的总数的变量
    int ans = 0;

    // 3. 外层循环：遍历从 L 到 R 之间的每一个正整数 i
    for (int i = L; i <= R; i++) {

        // 4. 用临时变量接住 i，准备进行拆解
        int temp = i;

        // 5. 准备用于记录当前这个数字包含几个 '2' 的变量
        int count2 = 0;

        // 6. 内层循环：经典的数位分离
        while (temp > 0) {
            // 获取当前最末位的数字
            int digit = temp % 10;

            // 如果这个末位数字是 2，把计数器加一
            if (digit == 2) {
                count2++;
            }

            // 剥掉已经检查过的最末位
            temp = temp / 10;
        }

        // 7. 内层剥离结束后，判断数字 '2' 出现的次数是否恰好等于 3
        if (count2 == 3) {
            ans++; // 恰好是3次，说明找到一个美丽数，总数加一
        }
    }

    // 8. 循环外输出最终找到的总个数
    std::cout << ans << std::endl;

    return 0;
}
