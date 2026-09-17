#include <algorithm>
#include <iostream>

// a[i] 表示坐标 i 处的星星总亮度
// 题目中坐标最大 X_i <= 100000，所以数组开到 100005 即可
int a[100005];
// pre[i] 表示前缀和数组，存储从坐标 1 到 i 的星星亮度总和
int pre[100005];

int main() {
    int N, W;
    std::cin >> N >> W;  // 输入星星数量 N 和窗户宽度 W

    for (int i = 1; i <= N; i++) {
        int x, b;
        std::cin >> x >> b;  // 输入每颗星星的坐标 x 和亮度 b
        // 注意：同一个位置可能有多颗星星，所以这里使用 += 累加亮度
        a[x] += b;
    }

    // 计算前缀和
    // pre[i] = a[1] + ... + a[i]
    for (int i = 1; i <= 100000; i++) {
        pre[i] = pre[i - 1] + a[i];
    }

    int max_b = 0;  // 记录能看到的最大亮度

    // 枚举每一个可能的窗户起点 i
    // 窗户范围是 [i, i + W - 1]
    // 确保窗户右端点 i + W - 1 不超过最大坐标范围 100000
    for (int i = 1; i + W - 1 <= 100000; i++) {
        // 利用前缀和快速计算当前窗户内的亮度总和
        // 区间 [L, R] 的和为 pre[R] - pre[L-1]
        // 这里 L = i, R = i + W - 1
        int cur_b = pre[i + W - 1] - pre[i - 1];
        max_b = std::max(max_b, cur_b);  // 更新最大值
    }

    std::cout << max_b << std::endl;  // 输出结果
    return 0;
}