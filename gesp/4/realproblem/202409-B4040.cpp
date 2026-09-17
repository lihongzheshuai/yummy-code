/**
 * 题目: 【GESP】C++四级真题 luogu-B4040 [GESP202409 四级] 黑白方块
 * 题号: B4040
 * 归属: GESP4级 (202409认证真题)
 * 博客: https://www.coderli.com/gesp-4-luogu-b4040/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <string>

// 存储输入的网格图，每个字符串表示一行，'0'表示白色，'1'表示黑色
std::string str_ary[105];

/**
 * 检查从(x,y)位置开始的4x4子矩阵是否满足题目要求
 * @param x 子矩阵左上角的行坐标
 * @param y 子矩阵左上角的列坐标
 * @param n 网格总行数
 * @param m 网格总列数
 * @return 是否满足要求
 */
bool check(int x, int y, int n, int m) {
    // 首先检查是否越界
    if (x + 4 > n || y + 4 > m) {
        return false;
    }

    // 遍历4x4子矩阵的每个位置
    for (int i = x; i < x + 4; i++) {
        for (int j = y; j < y + 4; j++) {
            // 检查第1行和第4行是否全为白色(0)
            if (i == x || i == x + 3) {
                if (str_ary[i][j] != '0') {
                    return false;
                }
            }

            // 检查第2行和第3行的第1列和第4列是否为白色(0)
            if (j == y || j == y + 3) {
                if (str_ary[i][j] != '0') {
                    return false;
                }
            }

            // 检查第2行和第3行的中间两列是否为黑色(1)
            if ((i == x + 1 || i == x + 2) && (j == y + 1 || j == y + 2)) {
                if (str_ary[i][j] != '1') {
                    return false;
                }
            }
        }
    }
    return true;
}

int main() {
    // 读取测试用例数量
    int t;
    std::cin >> t;

    // 处理每个测试用例
    while (t--) {
        // 读取网格的行数和列数
        int n, m;
        std::cin >> n >> m;

        // 读入网格数据
        for (int i = 0; i < n; i++) {
            std::cin >> str_ary[i];
        }

        // 标记是否找到符合要求的子矩阵
        bool flag = false;

        // 枚举所有可能的左上角起点
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // 检查以(i,j)为左上角的4x4子矩阵是否符合要求
                if (check(i, j, n, m)) {
                    std::cout << "Yes" << std::endl;
                    flag = true;
                    break;
                }
            }
            if (flag) {
                break;
            }
        }

        // 如果没有找到符合要求的子矩阵，输出No
        if (!flag) {
            std::cout << "No" << std::endl;
        }
    }
    return 0;
}
