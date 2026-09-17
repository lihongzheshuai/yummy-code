/**
 * 题目: 【GESP】C++四级真题 luogu-B4415 [GESP202509 四级] 排兵布阵
 * 题号: B4415
 * 归属: GESP4级 (202509认证真题)
 * 解法: 解法 1 / 共 2 种解法
 * 博客: https://www.coderli.com/gesp-4-luogu-b4415/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>

int num_ary[15][15]; // 存储地图：1 表示可排兵，0 表示不可排兵
int main() {
    int n, m;
    std::cin >> n >> m; // 读入行数 n 和列数 m
    // 读入地图数据
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> num_ary[i][j];
        }
    }

    int max_count = 0; // 记录最大合法矩形中的网格数

    // 枚举矩形左上角 (i,j)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // 枚举矩形右下角 (k,l)，要求 k≥i，l≥j
            for (int k = i; k < n; k++) {
                for (int l = j; l < m; l++) {
                    int count = 0;    // 当前矩形内 1 的个数
                    bool allOne = true; // 假设当前矩形全为 1

                    // 检查矩形内部是否全为 1
                    for (int x = i; x <= k; x++) {
                        for (int y = j; y <= l; y++) {
                            if (num_ary[x][y] == 1) {
                                count++; // 统计 1 的个数
                            } else {
                                allOne = false; // 出现 0，标记不合法
                                count = 0;        // 面积归零
                                break;            // 提前退出内层循环
                            }
                        }
                        if (!allOne) {
                            break; // 提前退出外层循环
                        }
                    }

                    // 若矩形合法，则尝试更新答案
                    if (allOne) {
                        max_count = std::max(max_count, count);
                    }
                }
            }
        }
    }

    std::cout << max_count << std::endl; // 输出最大网格数
    return 0;
}
