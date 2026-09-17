/**
 * 题目: 【GESP】C++一级练习 luogu-B2012, 甲流疫情死亡率
 * 题号: B2012
 * 归属: GESP1级
 * 博客: https://www.coderli.com/gesp-1-luogu-b2012/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <cstdio> // 引入标准输入输出库

int main() {
    int a, b; // 定义两个整数变量 a 和 b
    scanf("%d%d", &a, &b); // 从标准输入读取确诊数 a 和死亡数 b
    printf("%.3f%%", (double)b / (double)a * 100.0); // 计算死亡率并以百分数形式输出，保留三位小数
    return 0; // 返回 0，表示程序正常结束
}
