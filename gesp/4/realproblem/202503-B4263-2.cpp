/**
 * 题目: 【GESP】C++四级真题 luogu-B4263 [GESP202503 四级] 荒地开垦
 * 题号: B4263
 * 归属: GESP4级 (202503认证真题)
 * 解法: 解法 2 / 共 2 种解法
 * 博客: https://www.coderli.com/gesp-4-luogu-b4263/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>

// 存储地图数据的字符串数组
std::string str_ary[1005];
// 方向数组,用于遍历上下左右四个方向
const int di[4] = {-1, 1, 0, 0};  // 行方向偏移
const int dj[4] = {0, 0, -1, 1};  // 列方向偏移
// 记录每个位置周围杂物的数量
int bad_count_ary[1005][1005];
// 记录每个杂物位置可以增加的开垦数量
int cnt[1005][1005];

// 检查位置是否越界或为荒地
bool check(int x, int y, int n, int m) {
    if (x < 0 || x >= n || y < 0 || y >= m || str_ary[x][y] == '.') {
        return true;
    }
    return false;
}

// 检查一个位置四周的杂物情况
bool check_point(int x, int y, int n, int m, int& bad_count) {
    for (int i = 0; i < 4; i++) {
        int nx = x + di[i];
        int ny = y + dj[i];
        if (!check(nx, ny, n, m)) {  // 如果周围有杂物
            bad_count++;
        }
    }
    return bad_count > 0 ? false : true;  // 有杂物返回false，无杂物返回true
}

int main() {
    int n, m;
    std::cin >> n >> m;  // 输入地图大小
    // 输入地图数据
    for (int i = 0; i < n; i++) {
        std::cin >> str_ary[i];
    }

    int original_count = 0;  // 记录不清除杂物时可开垦的数量
    // 第一次遍历：计算原始可开垦数量和记录每个位置周围的杂物数
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int temp_count = 0;
            int bad_count = 0;
            if (str_ary[i][j] == '.' && check_point(i, j, n, m, bad_count)) {
                original_count++;  // 如果是可开垦的荒地，计数加1
            }
            bad_count_ary[i][j] = bad_count;  // 记录周围杂物数
        }
    }

    // 第二次遍历：统计每个杂物位置对周围荒地的影响
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // 如果是只受一个杂物影响的荒地
            if (str_ary[i][j] == '.' && bad_count_ary[i][j] == 1) {
                // 找到影响它的那个杂物，并增加该杂物的计数
                for (int k = 0; k < 4; k++) {
                    int nx = i + di[k];
                    int ny = j + dj[k];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
                        str_ary[nx][ny] == '#')
                        cnt[nx][ny]++;  // 该杂物位置的增益计数加1
                }
            }
        }
    }

    int best = 0;  // 记录清除一个杂物后最大的增益
    // 第三次遍历：计算清除每个杂物位置能获得的最大增益
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (str_ary[i][j] == '#') {
                int gain = cnt[i][j];  // 来自周围荒地的增益
                // 再看看它自己变成荒地后，周围有没有别的 '#'
                int bad = 0;
                for (int k = 0; k < 4; k++) {
                    int ni = i + di[k], nj = j + dj[k];
                    if (ni >= 0 && ni < n && nj >= 0 && nj < m &&
                        str_ary[ni][nj] == '#')
                        bad++;  // 统计周围杂物数
                }
                if (bad == 0) {
                    gain++;    // 它自己也能开垦
                }
                best = std::max(best, gain);  // 更新最大增益
            }
        }
    }

    // 输出最终结果：原始可开垦数量 + 清除一个杂物后的最大增益
    std::cout << original_count + best;
    return 0;
}
