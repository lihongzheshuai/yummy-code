/**
 * 题目: 【GESP】C++三级真题 luogu-B4413 [GESP202509 三级] 数组清零
 * 题号: B4413
 * 归属: GESP3级 (202509认证真题)
 * 博客: https://www.coderli.com/gesp-3-luogu-b4413/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>

int num_ary[105]; // 存放数组，最多100个元素
int main() {
    int n;
    std::cin >> n; // 读入数组长度
    int count = 0; // 记录操作次数
    for (int i = 0; i < n; i++) {
        std::cin >> num_ary[i]; // 读入数组元素
    }
    bool flag = false; // 标记数组是否全为0
    while (true) {
        flag = true; // 假设已全部清零
        int min = 101; // 初始化最小值（大于题设上限100）
        int max = 0;   // 初始化最大值
        int max_idx = -1; // 最大值下标
        for (int i = 0; i < n; i++) {
            if (num_ary[i] != 0) {
                flag = false; // 发现非零，未清零
            } else {
                continue; // 零元素跳过
            }
            // 更新非零最小值
            if (num_ary[i] < min && num_ary[i] != 0) {
                min = num_ary[i];
            }
            // 更新最大值及其下标（取最右）
            if (num_ary[i] >= max) {
                max = num_ary[i];
                max_idx = i;
            }
        }
        if (flag) {
            break; // 全部清零，退出循环
        }
        // 将最大元素减去最小元素
        num_ary[max_idx] -= min;
        count++; // 操作次数+1
    }

    std::cout << count << std::endl; // 输出总操作次数
    return 0;
}
