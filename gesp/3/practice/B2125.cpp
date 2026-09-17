/**
 * 题目: 【GESP】C++三级练习 luogu-B2125 最高分数的学生姓名
 * 题号: B2125
 * 归属: GESP3级
 * 博客: https://www.coderli.com/gesp-3-luogu-b2125/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include<iostream>
#include<string>

int main() {
    // 读取学生人数
    int n;
    std::cin >> n;

    // 初始化最高分数为-1，最高分学生姓名为空
    int max = -1;
    std::string max_name;

    // 循环读取每个学生的分数和姓名
    for (int i = 0; i < n; i++) {
        int point;          // 存储当前学生分数
        std::string name;   // 存储当前学生姓名
        std::cin >> point >> name;

        // 如果当前分数高于最高分，更新最高分和对应学生姓名
        if (point > max) {
            max = point;
            max_name = name;
        }
    }

    // 输出最高分学生的姓名
    std::cout << max_name;
    return 0;
}
