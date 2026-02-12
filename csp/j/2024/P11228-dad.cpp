#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>

// 全局变量，用于存储地图和访问标记
std::string s[1005];
int vis[1005][1005];

int main() {
    // 优化 I/O 效率
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T;  // 读取数据组数
    while (T--) {
        int n, m, k;
        std::cin >> n >> m >> k;  // 读取地图行数、列数和操作次数
        int x, y, d;
        std::cin >> x >> y >> d;  // 读取起始坐标 (x, y) 和初始朝向 d

        // 读取地图内容
        for (int i = 0; i < n; i++) {
            std::cin >> s[i];
        }

        int ans = 1;    // 记录经过的去重位置数量，初始位置算 1 个
        int cur_d = d;  // 当前朝向
        // 将输入的 1-based 坐标转换为 0-based 坐标，方便数组访问
        int cur_x = x - 1;
        int cur_y = y - 1;

        // 标记起始位置为已访问
        vis[cur_x][cur_y] = 1;

        // 模拟 k 次操作
        while (k--) {
            switch (cur_d) {
                case 0:  // 朝向东 (East)
                    // 判断下一步位置 (x, y+1) 是否在地图内且为空地
                    if (cur_y + 1 < m && s[cur_x][cur_y + 1] == '.') {
                        // 如果该位置未被访问过，则增加计数并标记
                        if (vis[cur_x][cur_y + 1] == 0) {
                            vis[cur_x][cur_y + 1] = 1;
                            ans++;
                        }
                        cur_y++;  // 向东移动一步
                    } else {
                        cur_d = 1;  // 遇到障碍或出界，向右转（变为向南）
                    }
                    break;
                case 1:  // 朝向南 (South)
                    // 判断下一步位置 (x+1, y) 是否在地图内且为空地
                    if (cur_x + 1 < n && s[cur_x + 1][cur_y] == '.') {
                        if (vis[cur_x + 1][cur_y] == 0) {
                            vis[cur_x + 1][cur_y] = 1;
                            ans++;
                        }
                        cur_x++;  // 向南移动一步
                    } else {
                        cur_d = 2;  // 向右转（变为向西）
                    }
                    break;
                case 2:  // 朝向西 (West)
                    // 判断下一步位置 (x, y-1) 是否在地图内且为空地
                    if (cur_y - 1 >= 0 && s[cur_x][cur_y - 1] == '.') {
                        if (vis[cur_x][cur_y - 1] == 0) {
                            vis[cur_x][cur_y - 1] = 1;
                            ans++;
                        }
                        cur_y--;  // 向西移动一步
                    } else {
                        cur_d = 3;  // 向右转（变为向北）
                    }
                    break;
                case 3:  // 朝向北 (North)
                    // 判断下一步位置 (x-1, y) 是否在地图内且为空地
                    if (cur_x - 1 >= 0 && s[cur_x - 1][cur_y] == '.') {
                        if (vis[cur_x - 1][cur_y] == 0) {
                            vis[cur_x - 1][cur_y] = 1;
                            ans++;
                        }
                        cur_x--;  // 向北移动一步
                    } else {
                        cur_d = 0;  // 向右转（变为向东）
                    }
                    break;
            }
        }

        // 清空 visited 数组，为下一组数据做准备
        // 注意：这里使用的是全局 vis 数组，需要重置
        memset(vis, 0, sizeof(vis));

        std::cout << ans << std::endl;  // 输出结果
    }
    return 0;
}