/**
 * 题目: 【GESP】C++一级练习BCQM3024，输入-计算-输出-5
 * 题号: 3024
 * 归属: GESP1级
 * 博客: https://www.coderli.com/gesp-1-bcqm3024/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <cstdio>

// 主函数入口
int main() {
    // 定义两个整型变量
    // a - 班级人数
    // b - 每人种树数量
    int a, b;

    // 从标准输入读取两个整数
    scanf("%d%d", &a, &b);

    // 计算并输出总的种树数量
    // a * b 计算班级总的种树数量
    printf("总的棵数：%d", a * b);

    // 程序正常结束
    return 0;
}
