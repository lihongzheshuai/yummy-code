/**
 * 题目: 【GESP】C++三级练习 luogu-P1161 开灯
 * 题号: P1161
 * 归属: GESP3级
 * 博客: https://www.coderli.com/gesp-3-luogu-p1161/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>

// 用于存储每个灯的状态的数组，0表示关闭，1表示打开
int array[2000005];
int main() {
    // n表示操作次数
    int n;
    std::cin >> n;
    // 循环处理每次操作
    for (int i=0; i < n; i++) {
        // a为实数倍数，t为操作次数上限
        double a;
        int t;
        std::cin >> a >> t;
        // 对于每次操作，计算需要改变状态的灯的编号
        for (int j = 1; j <=t; j++) {
            // 计算当前需要改变状态的灯的编号
            int idx = a * j;
            // 使用异或操作切换灯的状态（0变1，1变0）
            array[idx] ^= 1;
        }
    }
    // 遍历所有可能的灯，找出唯一一个打开的灯
    for (int i=0; i < 2000005; i++) {
        // 如果找到值为1的位置，说明这盏灯是打开的
        if (array[i] == 1) {
            std::cout << i << " ";
        }
    }
    return 0;
}
