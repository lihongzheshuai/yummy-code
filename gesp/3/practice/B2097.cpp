/**
 * 题目: 【GESP】C++三级练习 luogu-B2097 最长平台
 * 题号: B2097
 * 归属: GESP3级
 * 博客: https://www.coderli.com/gesp-3-luogu-b2097/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include<iostream>
#include<cmath>

int main() {
    // 读取数组长度
    int n;
    std::cin >> n;
    // count用于记录当前平台长度
    int count = 0;
    // max_n用于记录最长平台长度
    int max_n = 0;
    // last_num用于记录上一个数字，初始值-1表示还未读取任何数字
    int last_num = -1;
    // 循环读取n个数字
    while (n--) {
        // 读取当前数字
        int cur_num;
        std::cin >> cur_num;
        // 如果是第一个数字
        if (last_num == -1) {
            last_num = cur_num;
            count++;
            continue;
        }
        // 如果当前数字与上一个数字相同，平台长度加1
        if (cur_num == last_num) {
            count++;
        } else {
            // 如果不同，更新最长平台长度
            max_n = std::max(max_n, count);
            // 重置last_num和count，开始新的平台计数
            last_num = cur_num;
            count = 1;
        }
    }
    // 输出最长平台长度
    std::cout << max_n;
    return 0;
}
