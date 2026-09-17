/**
 * 题目: 【GESP】C++五级真题（前缀和思想考点） luogu-P10719 [GESP202406 五级] 黑白格
 * 题号: P10719
 * 归属: GESP5级 (202406认证真题)
 * 博客: https://www.coderli.com/gesp-5-luogu-p10719/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <vector>

// 前缀和数组，pre_sum[i][j] 表示从 (1,1) 到 (i,j) 的矩形中黑色格子的总数
int pre_sum[105][105];

int main() {
    int n, m, k;
    std::cin >> n >> m >> k;          // 读入行数、列数、至少需要的黑色格子数 k

    std::vector<std::string> strs(n);
    for (int i = 0; i < n; i++) {
        std::cin >> strs[i];          // 读入每行的 01 串，'1' 表示黑色格子
    }

    // 计算二维前缀和，注意下标从 1 开始，方便边界处理
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // 计算二维前缀和：pre_sum[i+1][j+1] 表示从 (1,1) 到 (i+1,j+1) 矩形内黑色格子总数
            // 递推公式：当前矩形和 = 上方矩形和 + 左方矩形和 - 左上重叠矩形和 + 当前格子值
            // 这样即可 O(1) 得到任意子矩形和，为后续四重循环快速判断提供基础
            pre_sum[i + 1][j + 1] = pre_sum[i][j + 1] + pre_sum[i + 1][j] - pre_sum[i][j]
                                  + (strs[i][j] == '1' ? 1 : 0);
        }
    }

    bool flag = false;                // 标记是否找到满足条件的子矩形
    int min_count = n * m;            // 初始化最小格子数为整个网格大小

    // 四重循环枚举所有可能的子矩形
    // (i,j) 为子矩形左上角，(l,r) 为右下角
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int l = i; l <= n; l++) {
                for (int r = j; r <= m; r++) {
                    // 利用前缀和快速计算当前子矩形内的黑色格子数
                    // 利用二维前缀和公式：子矩形 (i..l, j..r) 的黑色格子数
                    // = 右下角大矩形和 - 上方矩形和 - 左侧矩形和 + 左上角重叠矩形和
                    int cur_count = pre_sum[l][r] - pre_sum[i - 1][r]
                                  - pre_sum[l][j - 1] + pre_sum[i - 1][j - 1];
                    if (cur_count >= k) {
                        // 更新最小格子数
                        min_count = std::min(min_count, (l - i + 1) * (r - j + 1));
                        flag = true;
                    }
                }
            }
        }
    }

    // 输出结果，若未找到则输出 0
    if (flag) {
        std::cout << min_count << std::endl;
    } else {
        std::cout << 0 << std::endl;
    }
    return 0;
}
