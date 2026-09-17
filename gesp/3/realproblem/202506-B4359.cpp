/**
 * 题目: 【GESP】C++三级真题 luogu-B4359 [GESP202506 三级] 分糖果
 * 题号: B4359
 * 归属: GESP3级 (202506认证真题)
 * 博客: https://www.coderli.com/gesp-3-luogu-b4359/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>

int main() {
    // 读取小朋友的数量
    int n;
    std::cin >> n;

    // 总糖果数和上一个小朋友分到的糖果数
    long long sum = 0;
    int last_count = 0;

    // 遍历每个小朋友
    for (int i = 0; i < n; i++) {
        // 读取当前小朋友至少需要的糖果数
        int a;
        std::cin >> a;

        // 如果当前小朋友需要的糖果数大于前一个小朋友的糖果数
        if (a > last_count) {
            // 直接分配所需的糖果数
            sum += a;
            last_count = a;
        } else {
            // 否则分配比前一个小朋友多一个的糖果数
            sum += last_count + 1;
            last_count = last_count + 1;
        }
    }

    // 输出最少需要的总糖果数
    std::cout << sum << std::endl;
    return 0;
}
