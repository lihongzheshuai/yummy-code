/**
 * 题目: 【CSP】CSP-J 2019 江西真题 | 次大值 luogu-P5682 （适合GESP四、五级及以上考生练习）
 * 题号: P5682
 * 归属: GESP5级
 * 解法: 解法 1 / 共 2 种解法
 * 博客: https://www.coderli.com/csp-j-2019-p5682/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <algorithm>
#include <iostream>

// 全局数组，防止申请大空间时引发内存溢出问题（栈溢出）
int ary[200005];

int main() {
    int n;
    std::cin >> n;

    // 读入输入数据
    for (int i = 0; i < n; i++) {
        std::cin >> ary[i];
    }

    // 对数组进行升序排序，时间复杂度 O(N log N)
    std::sort(ary, ary + n);

    int count_diff = 1; // 记录找到了多少个【不同的数字】
    int big_one = ary[n - 1]; // 预设数组最后一个元素（排序后全局最大的数字）
    int big_two = 0, big_thr = 0; // 用来存第二大（次大）和第三大的数字

    // 因为排序过了，我们从后往前遍历寻找严格的次大和第三大数字即可
    for (int i = n - 2; i >= 0; i--) {
        // 如果已经成功找到了三个最大且彼此不同的数字，就可以提前退出循环以节约时间
        if (count_diff == 3) {
            break;
        }
        // 当我们只录入了一个最大数，且当前遇到的数字不同于它时，它就是第二大数字
        if (count_diff == 1 && ary[i] != big_one) {
            count_diff++;
            big_two = ary[i];
        }
        // 当我们已经录入了两个数值，且当前遇到的数字不同于它们时，它就是第三大数字
        if (count_diff == 2 && ary[i] != big_two) {
            count_diff++;
            big_thr = ary[i];
        }
    }

    // 根据收集到的不同的数字个数（范围 1 到 3），开始分情况结算
    if (count_diff == 1) {
        // 数据里只有一种相同的数字，取模总是 0，符合条件的唯一数字不足两个
        std::cout << -1;
    } else if (count_diff == 2) {
        // 数据去重后只有两种数字，最大的取模情况是由小的数得到，即 big_two
        // 而严格次大的取模结果只能是大数%小数去产生，即：最大数字取模次大数字
        std::cout << big_one % big_two;
    } else {
        // 原数组含有超过三种以上的去重数字时：
        // 比较【第三大数字】与【最大数字对第二大数字取余】，选取它们中间的较大者
        std::cout << std::max(big_thr, big_one % big_two);
    }
    return 0;
}
