/**
 * 题目: 【GESP】C++四级练习 luogu-P5730 【深基5.例10】显示屏
 * 题号: P5730
 * 归属: GESP4级
 * 博客: https://www.coderli.com/gesp-4-luogu-p5730/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>

// 定义5x10的字符串数组,用于存储0-9数字的显示样式
std::string array[5][10];
int main() {
    // 数字0的显示样式
    array[0][0] = "XXX";
    array[1][0] = "X.X";
    array[2][0] = "X.X";
    array[3][0] = "X.X";
    array[4][0] = "XXX";

    // 数字1的显示样式
    array[0][1] = "..X";
    array[1][1] = "..X";
    array[2][1] = "..X";
    array[3][1] = "..X";
    array[4][1] = "..X";

    // 数字2的显示样式
    array[0][2] = "XXX";
    array[1][2] = "..X";
    array[2][2] = "XXX";
    array[3][2] = "X..";
    array[4][2] = "XXX";

    // 数字3的显示样式
    array[0][3] = "XXX";
    array[1][3] = "..X";
    array[2][3] = "XXX";
    array[3][3] = "..X";
    array[4][3] = "XXX";

    // 数字4的显示样式
    array[0][4] = "X.X";
    array[1][4] = "X.X";
    array[2][4] = "XXX";
    array[3][4] = "..X";
    array[4][4] = "..X";

    // 数字5的显示样式
    array[0][5] = "XXX";
    array[1][5] = "X..";
    array[2][5] = "XXX";
    array[3][5] = "..X";
    array[4][5] = "XXX";

    // 数字6的显示样式
    array[0][6] = "XXX";
    array[1][6] = "X..";
    array[2][6] = "XXX";
    array[3][6] = "X.X";
    array[4][6] = "XXX";

    // 数字7的显示样式
    array[0][7] = "XXX";
    array[1][7] = "..X";
    array[2][7] = "..X";
    array[3][7] = "..X";
    array[4][7] = "..X";

    // 数字8的显示样式
    array[0][8] = "XXX";
    array[1][8] = "X.X";
    array[2][8] = "XXX";
    array[3][8] = "X.X";
    array[4][8] = "XXX";

    // 数字9的显示样式
    array[0][9] = "XXX";
    array[1][9] = "X.X";
    array[2][9] = "XXX";
    array[3][9] = "..X";
    array[4][9] = "XXX";

    // 读入数字的位数
    int n;
    std::cin >> n;

    // 读入n位数字字符串
    std::string str;
    std::cin >> str;

    // 按行输出数字的显示效果
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < n; j++) {
            // 输出当前数字的当前行
            std::cout << array[i][str[j] - '0'];
            // 除了最后一个数字，每个数字后面都要加一个点
            if (j != n - 1) {
                std::cout << ".";
            }
        }
        // 每行结束换行
        std::cout << "\n";
    }
    return 0;
}
