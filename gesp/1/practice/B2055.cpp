/**
 * 题目: 【GESP】C++一级练习 luogu-B2055, 均值
 * 题号: B2055
 * 归属: GESP1级
 * 博客: https://www.coderli.com/gesp-1-luogu-b2055/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <cstdio>

int main() {
    int n; // 定义整数变量n，用于存储样本容量
    scanf("%d", &n); // 从标准输入读取n的值
    double ans = 0; // 定义浮点数变量ans，用于累加样本数据，初始化为0
    double a; // 定义浮点数变量a，用于存储每个样本数据
    for (int i = 0; i < n; i++) { // 循环n次，读取每个样本数据
        scanf("%lf", &a); // 从标准输入读取a的值
        ans += a; // 累加每个样本数据到ans
    }
    printf("%.4f", ans / n); // 输出计算的平均值，保留到小数点后4位
    return 0; // 返回0，表示程序执行成功
}
