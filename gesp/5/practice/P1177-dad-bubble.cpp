#include <iostream>

// 全局数组，大小 100005，足以存储题目给出的 N (1 <= N <= 10^5) 个数据
int ary[100005];

int main() {
    int N;
    // 读入需要排序的数字个数 N
    std::cin >> N;

    // 循环读入 N 个数字到数组 ary[] 中
    for (int i = 0; i < N; i++) {
        std::cin >> ary[i];
    }

    // 这实际上是一个「交换排序」（或者叫选择排序的变差，与冒泡排序类似），时间复杂度为
    // O(N^2) 注意：对于题目中 N <= 10^5 的数据，O(N^2) 算法会超时
    // (TLE)，这里仅作为基础算法演示 外层循环：遍历数组，确定 ary[i]
    // 的位置上是从 i 到末尾所有剩余元素中的最小值
    for (int i = 0; i < N; i++) {
        // 内层循环：比较从 i+1 开始到数组末尾的所有元素
        for (int j = i + 1; j < N; j++) {
            // 如果遇到比当前 ary[i] 更小的元素 ary[j]，就直接把它们交换
            if (ary[j] < ary[i]) {
                int tmp = ary[i];
                ary[i] = ary[j];
                ary[j] = tmp;
            }
        }
    }

    // 循环输出排好序的数据，每个数字后跟着一个空格
    for (int i = 0; i < N; i++) {
        std::cout << ary[i] << " ";
    }
    return 0;
}