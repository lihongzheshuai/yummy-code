/**
 * 题目: 【GESP】C++二级真题 luogu-B4411 [GESP202509 二级] 优美的数字
 * 题号: B4411
 * 归属: GESP2级 (202509认证真题)
 * 博客: https://www.coderli.com/gesp-2-luogu-b4411/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>

int main() {
    int n;
    std::cin >> n; // 读入正整数 n
    int count = 0; // 用于统计满足条件的数字个数
    for (int i = 1; i <= n; i++) { // 枚举 1 到 n 的每个数字
        bool flag = true; // 标记当前数字是否所有位都相同
        int cur_num = i;
        if (i < 10) {
            // 个位数一定满足条件
            count++;
        } else {
            int last_bit = cur_num % 10; // 取最低位
            cur_num /= 10;
            while (cur_num > 0) {
                int cur_bit = cur_num % 10; // 取当前最低位
                if (cur_bit != last_bit) {
                    // 如果有一位不同，则不满足条件
                    flag = false;
                    break;
                }
                cur_num /= 10; // 去掉最低位
            }
            if (flag) {
                // 如果所有位都相同，计数加一
                count++;
            }
        }
    }
    std::cout << count; // 输出结果
    return 0;
}
