/**
 * 题目: 【GESP】C++四级真题 luogu-B4501, [GESP202603 四级] 山之谷
 * 题号: B4501
 * 归属: GESP4级 (202603认证真题)
 * 博客: https://www.coderli.com/gesp-4-luogu-b4501/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <vector>

int main() {
    int N, M;
    std::cin >> N >> M;

    // 为了防止下标因为偏移计算越界，建议使用 N+2 和 M+2 大小的数组
    // 使用 std::vector 以支持可变的 N 和 M 动态大小分配，也可以直接声明静态大数组 int h[105][105]
    std::vector<std::vector<int>> h(N + 2, std::vector<int>(M + 2, 0));

    // 读入海拔高度（推荐起始下标为1，迎合我们一惯使用的坐标轴思维）
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            std::cin >> h[i][j];
        }
    }

    // 定义经典的方向数组（8个方向：左上, 上, 右上, 左, 右, 左下, 下, 右下）
    int dx[8] = {-1, -1, -1,  0, 0,  1, 1, 1};
    int dy[8] = {-1,  0,  1, -1, 1, -1, 0, 1};

    int ans = 0; // 记录山谷的总数量

    // 1. 全图扫描：依次检测地图中的每个坐标
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {

            bool isValley = true; // 默认它是个山谷，即“假设无罪”

            // 2. 八方向探测周围地形
            for (int k = 0; k < 8; k++) {
                int nx = i + dx[k]; // 算出邻居的横坐标
                int ny = j + dy[k]; // 算出邻居的纵坐标

                // 判断这个新算出的邻居坐标是否合法（不能越界跑出地图外）
                if (nx >= 1 && nx <= N && ny >= 1 && ny <= M) {

                    // 只要发现有一个合法的邻居，其海拔竟然严格”低于”中心点 (i,j)
                    if (h[nx][ny] < h[i][j]) {
                        isValley = false; // 说明中心点不是最低谷，推翻“假设”
                        break; // 后面的方向也不用看了，直接结束查岗
                    }
                }
            }

            // 8 个方向全部探查完毕并且中途没被推翻
            if (isValley) {
                ans++; // 山谷计数加一
            }
        }
    }

    // 输出最终找出的山谷数
    std::cout << ans << std::endl;

    return 0;
}
