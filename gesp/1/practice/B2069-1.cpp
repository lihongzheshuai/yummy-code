/**
 * 题目: 【GESP】C++一级练习 luogu-B2069, 求分数序列和
 * 题号: B2069
 * 归属: GESP1级
 * 解法: 解法 1 / 共 2 种解法
 * 博客: https://www.coderli.com/gesp-1-luogu-b2069/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <cstdio> // 包含输入输出流头文件

int main() {
    int n; // 定义整数n，用于存储输入的项数
    scanf("%d", &n); // 从输入流中读取n的值
    int m = 1; // 初始化分子母1
    int z = 2; // 初始化分子为2
    double sum = 0; // 初始化和为0
    for (int i = 1; i <= n; i++) { // 循环n次，计算前n项的和
        sum += (double)z / m; // 计算当前项的值并累加到sum
        int temp = z; // 保存当前分子的值
        z = m + z; // 更新下一个分子为当前分子加上当前分母
        m = temp; // 更新下一个分母为当前分子
    }
    printf("%.4f", sum); // 输出和，保留到小数点后4位

    return 0; // 返回0，表示程序执行成功
}
