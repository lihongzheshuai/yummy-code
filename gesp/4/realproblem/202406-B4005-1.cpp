/**
 * 题目: 【GESP】C++四级真题 luogu-B4005 [GESP202406 四级] 黑白方块
 * 题号: B4005
 * 归属: GESP4级 (202406认证真题)
 * 解法: 解法 1 / 共 2 种解法
 * 博客: https://www.coderli.com/gesp-4-luogu-b4005/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <cmath>
#include <iostream>
#include <string>

// 存储黑白方块矩阵，-1表示白色，1表示黑色
int ary[15][15];
// 存储前缀和数组
int sum[15][15];

// 检查指定矩形区域内黑白方块是否平衡
// 参数：f_row,f_col 左上角坐标，l_row,l_col 右下角坐标
bool check(int f_row, int f_col, int l_row, int l_col) {
    int sum = 0;
    // 遍历矩形区域
    for (int i = f_row; i <= l_row; i++) {
        for (int j = f_col; j <= l_col; j++) {
            sum += ary[i][j];
        }
    }
    // 如果和为0，说明黑白方块数量相等
    return sum == 0 ? true : false;
}

int main() {
    // 读入矩阵大小
    int n, m;
    std::cin >> n >> m;

    // 读入矩阵数据并计算前缀和
    for (int i = 1; i <= n; i++) {
        std::string r_str;
        std::cin >> r_str;
        for (int j = 1; j <= m; j++) {
            // 将0转换为-1(白色)，1保持不变(黑色)
            ary[i][j] = r_str[j - 1] == '0' ? -1 : 1;
            // 计算二维前缀和
            sum[i][j] =
                sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + ary[i][j];
        }
    }

    // 枚举所有可能的矩形区域
    int max_area = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = i; k <= n; k++) {
                for (int l = j; l <= m; l++) {
                    // 检查当前矩形是否平衡
                    if (check(i, j, k, l)) {
                        // 计算矩形面积并更新最大值
                        int area = (k - i + 1) * (l - j + 1);
                        max_area = std::max(max_area, area);
                    }
                }
            }
        }
    }
    // 输出结果
    std::cout << max_area;
    return 0;
}
