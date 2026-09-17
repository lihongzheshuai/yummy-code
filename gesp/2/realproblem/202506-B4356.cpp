/**
 * 题目: 【GESP】C++二级真题 luogu-B4356 [GESP202506 二级] 数三角形
 * 题号: B4356
 * 归属: GESP2级 (202506认证真题)
 * 博客: https://www.coderli.com/gesp-2-luogu-b4356/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>

int main() {
    // 读入直角边长的最大值n
    int n;
    std::cin >> n;

    // 计数器，记录满足条件的直角三角形数量
    int count = 0;

    // 遍历所有可能的直角边长组合
    for (int i = 1; i <= n; i++) {
        // j从i开始避免重复计数
        for (int j = i; j <= n; j++) {
            // 判断面积是否为整数：面积 = (i*j)/2
            if (i * j % 2 == 0) {
                count++;
            }
        }
    }

    // 输出结果
    std::cout << count << std::endl;
    return 0;
}
