#include <climits>
#include <cmath>
#include <iostream>

// 定义最大数组大小，根据题目要求 M, N <= 1000
int a[1005][1005];

int main() {
    int M, N, H;
    // 输入行数 M，列数 N，和最大高度差限制 H
    std::cin >> M >> N >> H;

    // 读取地图高度数据
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            std::cin >> a[i][j];
        }
    }

    int max_sum = INT_MIN;  // 用于记录满足条件区域的最大海拔之和

    // 遍历每一个可能的 3x3 区域的左上角起点 (i, j)
    // 因为停机坪是 3x3 的区域，所以 i 的范围是 0 到 M-3，j 的范围是 0 到 N-3
    for (int i = 0; i <= M - 3; i++) {
        for (int j = 0; j <= N - 3; j++) {
            int tmp_sum = 0;
            int tmp_max = INT_MIN;
            int tmp_min = INT_MAX;

            // 遍历 3x3 区域内的每一个点 (k, l)
            // k 从 i 到 i+2，l 从 j 到 j+2
            for (int k = i; k <= i + 2; k++) {
                for (int l = j; l <= j + 2; l++) {
                    tmp_sum += a[k][l];
                    // 更新区域内的最大值和最小值
                    tmp_max = std::max(tmp_max, a[k][l]);
                    tmp_min = std::min(tmp_min, a[k][l]);
                }
            }

            // 判断最大高度差是否满足条件：max - min <= H
            if (tmp_max - tmp_min > H) {
                continue;
            }

            // 如果满足条件，更新全局最大和
            max_sum = std::max(max_sum, tmp_sum);
        }
    }

    std::cout << max_sum << '\n';
    return 0;
}
