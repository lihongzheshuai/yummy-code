/**
 * 题目: 【GESP】C++三级真题 luogu-B4358 [GESP202506 三级] 奇偶校验
 * 题号: B4358
 * 归属: GESP3级 (202506认证真题)
 * 博客: https://www.coderli.com/gesp-3-luogu-b4358/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>

int main() {
    // 读取数据个数
    int n;
    std::cin >> n;

    // 统计所有数字二进制中1的总数
    int count = 0;
    for (int i = 0; i < n; i++) {
        // 读取每个数字
        int c;
        std::cin >> c;

        // 对每个数字进行二进制分解，统计1的个数
        while (c) {
            // 获取最低位
            int bit = c % 2;
            // 如果最低位是1，计数加1
            if (bit == 1) {
                count++;
            }
            // 右移一位，继续处理
            c /= 2;
        }
    }

    // 根据1的总数判断校验码：偶数个1校验码为0，奇数个1校验码为1
    int y = count % 2 == 0 ? 0 : 1;
    // 输出1的总数和校验码
    std::cout << count << " " << y << std::endl;
    return 0;
}
