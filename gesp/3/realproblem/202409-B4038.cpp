/**
 * 题目: 【GESP】C++三级真题 luogu-B4038 [GESP202409 三级] 平衡序列
 * 题号: B4038
 * 归属: GESP3级 (202409认证真题)
 * 博客: https://www.coderli.com/gesp-3-luogu-b4038/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>

int main() {
    // 读取测试用例数量
    int t;
    std::cin >> t;
    // 遍历每个测试用例
    for (int i = 0; i < t; i++) {
        // 读取序列长度
        int n;
        std::cin >> n;
        // 定义数组存储序列
        int ary[n];
        // 计算序列总和
        int sum = 0;
        for (int j = 0; j < n; j++) {
            std::cin >> ary[j];
            sum += ary[j];
        }
        // 标记是否找到平衡点
        bool flag = false;
        // 左侧序列和
        int l_sum = 0;
        // 遍历每个位置，寻找平衡点
        for (int j = 0; j < n; j++) {
            l_sum += ary[j];
            // 判断左侧和是否等于右侧和
            // 右侧和 = 总和 - 左侧和
            if (l_sum == sum - l_sum) {
                flag = true;
                break;
            }
        }

        // 输出结果
        if (flag) {
            std::cout << "Yes" << std::endl;
            flag = false;
        } else {
            std::cout << "No" << std::endl;
        }
    }
    return 0;
}
