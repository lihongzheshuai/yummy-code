/**
 * 题目: 【GESP】C++四级真题 luogu-B4557 [GESP202606 四级] 扫雷
 * 题号: B4557
 * 归属: GESP4级 (202606认证真题)
 * 博客: https://www.coderli.com/gesp-4-luogu-b4557/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>

// 二维数组记录每个位置是否为雷区
bool mine[505][505];

// 八个方向的偏移量：上、下、左、右、左上、右上、左下、右下
int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};

int main() {
    // 读入地图行数、列数和雷区数量
    int n, m, q;
    std::cin >> n >> m >> q;

    // 读入每个雷区的位置并标记
    for (int i = 0; i < q; i++) {
        int r, c;
        std::cin >> r >> c;
        mine[r][c] = true;
    }

    // 遍历整个地图
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            // 输出元素之间的空格分隔
            if (j > 1) {
                std::cout << " ";
            }
            if (mine[i][j]) {
                // 当前位置是雷区，输出 '*'
                std::cout << "*";
            } else {
                // 当前位置不是雷区，统计周围 8 个方向的雷区数量
                int count = 0;
                for (int d = 0; d < 8; d++) {
                    int ni = i + dx[d];
                    int nj = j + dy[d];
                    // 判断邻域坐标是否在地图范围内
                    if (ni >= 1 && ni <= n && nj >= 1 && nj <= m && mine[ni][nj]) {
                        count++;
                    }
                }
                std::cout << count;
            }
        }
        std::cout << std::endl;
    }
    return 0;
}
