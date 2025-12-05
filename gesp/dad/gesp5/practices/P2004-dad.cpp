#include <climits>
#include <iostream>

typedef long long ll;

// a[i][j] 存储每个格子的价值
// pre[i][j] 存储 (1,1) 到 (i,j) 的矩形区域内的价值总和（二维前缀和）
int a[1005][1005];
ll pre[1005][1005];

int main() {
    // N, M 为地图的宽和长，C 为首都的边长
    int N, M, C;
    std::cin >> N >> M >> C;

    // 读取输入并计算二维前缀和
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            std::cin >> a[i][j];
            // 二维前缀和公式：
            // 当前点的前缀和 = 上方的前缀和 + 左方的前缀和 -
            // 左上方重复计算的部分 + 当前点的值
            pre[i][j] =
                pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + a[i][j];
        }
    }

    // 初始化最大价值为 long long 的最小值，防止因负数导致错误
    ll max_sum = LLONG_MIN;
    int x, y;  // 记录最优解的左上角坐标

    // 枚举所有可能的首都左上角坐标 (i, j)
    // 注意边界条件：i + C - 1 <= N 且 j + C - 1 <= M
    for (int i = 1; i + C - 1 <= N; i++) {
        for (int j = 1; j + C - 1 <= M; j++) {
            // 利用二维前缀和计算以 (i, j) 为左上角，边长为 C
            // 的正方形区域的价值和 公式：右下角前缀和 - 上方多余部分 -
            // 左方多余部分 + 左上方多减的部分
            ll cur_sum = pre[i + C - 1][j + C - 1] - pre[i - 1][j + C - 1] -
                         pre[i + C - 1][j - 1] + pre[i - 1][j - 1];

            // 如果当前区域价值更大，则更新最大值和坐标
            if (cur_sum > max_sum) {
                max_sum = cur_sum;
                x = i;
                y = j;
            }
        }
    }

    // 输出结果
    std::cout << x << " " << y << "\n";
    return 0;
}