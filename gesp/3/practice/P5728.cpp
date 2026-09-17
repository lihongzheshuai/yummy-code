/**
 * 题目: 【GESP】C++三级练习 luogu-P5728 【深基5.例5】旗鼓相当的对手
 * 题号: P5728
 * 归属: GESP3级
 * 博客: https://www.coderli.com/gesp-3-luogu-p5728/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <cmath>
#include <iostream>

int main() {
    // 读取学生人数N
    int N;
    std::cin >> N;

    // 定义三个数组分别存储语文、数学、英语成绩
    int one_ary[N];   // 语文成绩数组
    int two_ary[N];   // 数学成绩数组
    int three_ary[N]; // 英语成绩数组

    // 读入每个学生的三科成绩
    for (int i = 0; i < N; i++) {
        std::cin >> one_ary[i] >> two_ary[i] >> three_ary[i];
    }

    // 统计旗鼓相当对手的对数
    int count = 0;

    // 双重循环遍历所有可能的学生对
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            // 判断是否为旗鼓相当的对手：
            // 1. 每科分差不超过5分
            // 2. 总分差不超过10分
            if (std::abs(one_ary[j] - one_ary[i]) <= 5 &&
                std::abs(two_ary[j] - two_ary[i]) <= 5 &&
                std::abs(three_ary[j] - three_ary[i]) <= 5 &&
                std::abs(one_ary[i] + two_ary[i] + three_ary[i] -
                         (one_ary[j] + two_ary[j] + three_ary[j])) <= 10) {
                count++;
            }
        }
    }

    // 输出结果
    std::cout << count << std::endl;
    return 0;
}
