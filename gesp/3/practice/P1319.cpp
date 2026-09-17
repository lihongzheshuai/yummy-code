/**
 * 题目: 【GESP】C++三级练习 luogu-P1319 压缩技术
 * 题号: P1319
 * 归属: GESP3级
 * 博客: https://www.coderli.com/gesp-3-luogu-p1319/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>

int main() {
    // 读取矩阵大小 N
    int n;
    std::cin >> n;

    // 当前需要输出的数字(0或1)
    int cur_count;
    // 当前正在处理的数字(初始为0)
    int cur_num = 0;
    // 当前行已输出的字符数
    int line_count = 0;

    // 持续读取压缩码中的数字
    while(std::cin >> cur_count) {
        // 根据当前数字(cur_count)重复输出cur_num指定次数
        for (int i = 0; i < cur_count; i++) {
            // 输出当前数字
            std::cout << cur_num;
            line_count++;

            // 如果已经输出了n个字符，换行并重置行计数
            if (line_count == n) {
                std::cout << "\n";
                line_count = 0;
            }
        }
        // 切换当前数字(0变1，1变0)
        cur_num ^= 1;
    }
    return 0;
}
