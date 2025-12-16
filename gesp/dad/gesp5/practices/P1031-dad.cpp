#include <iostream>

int a[105];  // 定义数组存放每堆纸牌数，大小略大于100
int main() {
    int N;
    std::cin >> N;  // 输入纸牌堆数 N
    int sum = 0;    // 用于存储纸牌总数
    for (int i = 1; i <= N; i++) {
        std::cin >> a[i];  // 输入每堆纸牌的初始数量
        sum += a[i];       // 累加总数
    }
    int target = sum / N;  // 计算平均每堆纸牌应有的数量
    int step = 0;          // 记录移动次数

    // 从左向右遍历每一堆纸牌 (贪心算法)
    // 思想：如果当前堆不等于平均值，只能和右边相邻的堆进行交换（因为左边已经平衡了）
    for (int i = 1; i <= N; i++) {
        if (i == 1) {
            // 第一堆只能移向第二堆，或者从第二堆移入
            if (a[1] != target) {
                step++;  // 需要移动一次
                a[2] +=
                    a[1] -
                    target;  // 将差额加到下一堆（多退少补，只是数值上的转移）
                a[1] = target;  // 当前堆达到平均值
            }
        } else {
            // 处理后续的堆
            if (a[i] != target) {
                step++;                     // 需要移动一次
                a[i + 1] += a[i] - target;  // 将当前堆的盈亏转移给下一堆
                a[i] = target;              // 当前堆达到平均值
            }
        }
    }
    std::cout << step << std::endl;  // 输出最少移动次数
    return 0;
}