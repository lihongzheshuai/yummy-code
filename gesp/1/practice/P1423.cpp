/**
 * 题目: 【GESP】C++一级练习 luogu-P1423, 小玉在游泳
 * 题号: P1423
 * 归属: GESP1级
 * 博客: https://www.coderli.com/gesp-1-luogu-p1423/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <cstdio>
#include <iostream>
using namespace std;
int main() {
    double n; // 目标距离
    double sum = 0; // 已游的总距离
    double last = 0; // 上一步的游泳距离
    double current = 0; // 当前步的游泳距离
    scanf("%lf", &n); // 读取目标距离
    int count = 0; // 游泳步数计数器
    while (true) {
        count++; // 增加步数计数
        if (count == 1) { // 第一步游泳距离
            current = 2.0; // 初始化当前游泳距离为2米
            sum += current; // 累加到总距离
            last = current; // 更新上一步距离
        } else { // 后续游泳距离
            current = last * 0.98; // 当前距离为上一步的98%
            sum += current; // 累加到总距离
            last = current; // 更新上一步距离
        }
        if (sum >= n) { // 如果总距离达到或超过目标距离
            break; // 退出循环
        }
    }
    printf("%d", count); // 输出所需的步数
    return 0; // 程序结束
}
