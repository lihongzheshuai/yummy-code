/**
 * 题目: 【GESP】C++四级练习 luogu-P2550 [AHOI2001] 彩票摇奖
 * 题号: P2550
 * 归属: GESP4级
 * 博客: https://www.coderli.com/gesp-4-luogu-p2550/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>

// 存储所有购买的彩票号码的二维数组
int buy_ary[1005][7];
int main() {
    // n表示购买的彩票数量
    int n;
    std::cin >> n;

    // 存储中奖号码的数组
    int target[7] = {0};
    // 读入7个中奖号码
    for (int i = 0; i < 7; i++) {
        std::cin >> target[i];
    }

    // 存储各个奖项的中奖数量，从特等奖到六等奖
    int result[7] = {0};

    // 遍历每一张购买的彩票
    for (int i = 0; i < n; i++) {
        // count记录当前彩票匹配中奖号码的个数
        int count = 0;
        // 比较每一张彩票
        for (int j = 0; j < 7; j++) {
            // 读入当前彩票的号码
            std::cin >> buy_ary[i][j];
            // 将当前号码与所有中奖号码比较
            for (int k = 0; k < 7; k++) {
                if (buy_ary[i][j] == target[k]) {
                    count++;
                }
            }
        }
        // 如果有匹配的号码，更新对应奖项的中奖数量
        // 7-count的含义：7个匹配是特等奖(index 0)，6个匹配是一等奖(index 1)，以此类推
        if (count) {
            result[7 - count]++;
        }
    }

    // 按顺序输出各个奖项的中奖数量
    for (int i = 0; i < 7; i++) {
        std::cout << result[i] << " ";
    }
    return 0;
}
