#include <iostream>

// ary 数组用于存储输入的 01 矩阵
int ary[105][105];
// pre_ary 数组用于存储二维前缀和
// pre_ary[i][j] 表示以 (1, 1) 为左上角，(i, j) 为右下角的矩形区域内所有元素的和
int pre_ary[105][105];

int main() {
    int n, m;
    // 输入矩阵的行数 n 和列数 m
    std::cin >> n >> m;

    // 循环输入矩阵的每个元素
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            std::cin >> ary[i][j];
        }
    }

    // 计算二维前缀和
    // 递推公式：当前位置前缀和 = 上方前缀和 + 左方前缀和 - 左上方前缀和 +
    // 当前元素值
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            pre_ary[i][j] = pre_ary[i - 1][j] + pre_ary[i][j - 1] -
                            pre_ary[i - 1][j - 1] + ary[i][j];
        }
    }

    // max_sum 用于记录找到的最大正方形的边长
    // 注意：虽然变量名叫 max_sum，但在本题逻辑中它被用来存储边长
    int max_sum = 0;

    // 枚举所有可能的子矩形
    // (i, j) 表示子矩形的左上角坐标
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            // (k, l) 表示子矩形的右下角坐标
            for (int k = i; k <= n; k++) {
                for (int l = j; l <= m; l++) {
                    // 判断当前子矩形是否为正方形（行数等于列数）
                    if ((k - i + 1) == (l - j + 1)) {
                        // 利用前缀和计算该子矩形内所有元素的和
                        // 公式：右下角前缀和 - 上方区域前缀和 - 左方区域前缀和
                        // + 左上方区域前缀和
                        int sum = pre_ary[k][l] - pre_ary[i - 1][l] -
                                  pre_ary[k][j - 1] + pre_ary[i - 1][j - 1];

                        // 如果子矩形的元素和等于其面积（说明该区域内全为
                        // 1），且和大于 0 (k - i + 1) * (l - j + 1)
                        // 即为该正方形的面积
                        if (sum == (k - i + 1) * (l - j + 1) && sum > 0) {
                            // 更新最大正方形的边长
                            max_sum = std::max(max_sum, k - i + 1);
                        }
                    }
                }
            }
        }
    }

    // 输出最大正方形的边长
    std::cout << max_sum << std::endl;
    return 0;
}