/**
 * 题目: 【GESP】C++四级练习 luogu-P2615 [NOIP 2015 提高组] 神奇的幻方
 * 题号: P2615
 * 归属: GESP4级
 * 博客: https://www.coderli.com/gesp-4-luogu-p2615/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>

// 定义存储幻方的二维数组
int result[40][40];
int main() {
    int N;
    std::cin >> N;
    // 将1放在第一行的中间位置
    result[0][(N - 1) / 2] = 1;
    // 记录上一个数字的位置
    int last_i = 0;
    int last_j = (N - 1) / 2;

    // 从2开始依次填写每个数字
    for (int i = 2; i <= N * N; i++) {
        // 情况1：上一个数在第一行但不在最后一列
        if (last_i == 0 && last_j != N - 1) {
            last_i = N - 1;  // 移到最后一行
            last_j = last_j + 1;  // 右移一列
            result[last_i][last_j] = i;
        }
        // 情况2：上一个数在最后一列但不在第一行
        else if (last_i != 0 && last_j == N - 1) {
            last_i = last_i - 1;  // 上移一行
            last_j = 0;  // 移到第一列
            result[last_i][last_j] = i;
        }
        // 情况3：上一个数在第一行最后一列
        else if (last_i == 0 && last_j == N -1) {
            last_i += 1;  // 直接下移一行
            last_j = N - 1;
            result[last_i][last_j] = i;
        }
        // 情况4：其他情况
        else {
            // 如果右上方为空，填在右上方
            if (result[last_i - 1][last_j + 1] == 0) {
                last_i -= 1;  // 上移一行
                last_j += 1;  // 右移一列
                result[last_i][last_j] = i;
            }
            // 如果右上方已有数字，填在下方
            else {
                last_i += 1;  // 下移一行
                result[last_i][last_j] = i;
            }
        }
    }

    // 输出幻方
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << result[i][j] << " ";
        }
        std::cout << "\n";
    }
    return 0;
}
