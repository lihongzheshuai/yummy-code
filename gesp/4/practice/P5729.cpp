/**
 * 题目: 【GESP】C++四级练习 luogu-P5729 【深基5.例7】工艺品制作
 * 题号: P5729
 * 归属: GESP4级
 * 博客: https://www.coderli.com/gesp-4-luogu-p5729/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <cmath>
#include <iostream>

// 定义一个三维数组来表示立方体，每个元素表示一个小方块是否存在(1存在,0不存在)
int array[25][25][25];
int main() {
    // 输入立方体的长宽高
    int w, x, h;
    std::cin >> w >> x >> h;

    // 初始化立方体，所有小方块都存在
    for (int i = 1; i <= w; i++) {
        for (int j = 1; j <= x; j++) {
            for (int k = 1; k <= h; k++) {
                array[i][j][k] = 1;
            }
        }
    }

    // 输入切割次数
    int q;
    std::cin >> q;
    int count = 0;

    // 进行q次切割操作
    for (int i = 0; i < q; i++) {
        // 输入每次切割的两个对角点坐标
        int x1, y1, z1, x2, y2, z2;
        std::cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;

        // 将切割区域内的小方块标记为0（被切除）
        for (int j = x1; j <= x2; j++) {
            for (int k = y1; k <= y2; k++) {
                for (int l = z1; l <= z2; l++) {
                    array[j][k][l] = 0;
                }
            }
        }
    }

    // 统计剩余小方块的数量
    for (int j = 1; j <= w; j++) {
        for (int k = 1; k <= x; k++) {
            for (int l = 1; l <= h; l++) {
                count += array[j][k][l];
            }
        }
    }

    // 输出结果
    std::cout << count;
    return 0;
}
