/**
 * 题目: 【GESP】C++一级练习BCQM3054(luogu-B2013)，温度表达转化
 * 题号: 3054
 * 归属: GESP1级
 * 博客: https://www.coderli.com/gesp-1-bcqm3054/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <cstdio>

int main() {
    // 定义一个 double 类型的变量 f，用来存储输入的华氏温度
    // 因为温度可能是带小数的实数，所以必须用 double 而不是 int
    double f;
    scanf("%lf", &f); // 用 %lf 读入一个 double 类型的值

    // 按照公式计算摄氏温度：C = 5 * (F - 32) / 9
    double c = 5 * (f - 32) / 9;

    // 输出结果，保留小数点后 5 位
    // %.5f 中的 .5 表示保留 5 位小数
    printf("%.5f", c);

    return 0;
}
