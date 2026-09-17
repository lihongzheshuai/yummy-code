/**
 * 题目: 【GESP】C++四级真题 luogu-B4263 [GESP202503 四级] 荒地开垦
 * 题号: B4263
 * 归属: GESP4级 (202503认证真题)
 * 解法: 解法 1 / 共 2 种解法
 * 博客: https://www.coderli.com/gesp-4-luogu-b4263/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>

// 存储输入的地图数据
std::string str_ary[1005];

// 检查当前位置左边是否满足开垦条件
// x,y 为当前位置坐标，n,m为地图大小
bool check_left(int x, int y, int n, int m) {
    if (y == 0) {  // 如果在最左边，满足条件
        return true;
    }
    if (str_ary[x][y - 1] == '.') {  // 如果左边是荒地，满足条件
        return true;
    }
    return false;
}

// 检查当前位置右边是否满足开垦条件
bool check_right(int x, int y, int n, int m) {
    if (y == m - 1) {  // 如果在最右边，满足条件
        return true;
    }
    if (str_ary[x][y + 1] == '.') {  // 如果右边是荒地，满足条件
        return true;
    }
    return false;
}

// 检查当前位置上方是否满足开垦条件
bool check_up(int x, int y, int n, int m) {
    if (x == 0) {  // 如果在最上边，满足条件
        return true;
    }
    if (str_ary[x - 1][y] == '.') {  // 如果上方是荒地，满足条件
        return true;
    }
    return false;
}

// 检查当前位置下方是否满足开垦条件
bool check_down(int x, int y, int n, int m) {
    if (x == n - 1) {  // 如果在最下边，满足条件
        return true;
    }
    if (str_ary[x + 1][y] == '.') {  // 如果下方是荒地，满足条件
        return true;
    }
    return false;
}

// 检查当前位置四周是否都满足开垦条件
bool check_point(int x, int y, int n, int m) {
    if (check_left(x, y, n, m) && check_right(x, y, n, m) && check_up(x, y, n, m) && check_down(x, y, n, m)) {
        return true;
    }
    return false;
}

// 检查当前位置除了下方外是否都满足开垦条件
bool check_add_down(int x, int y, int n, int m) {
    if (str_ary[x][y] == '.' && check_left(x, y, n, m) && check_right(x, y, n, m) && check_up(x, y, n, m)) {
        return true;
    }
    return false;
}

// 检查当前位置除了上方外是否都满足开垦条件
bool check_add_up(int x, int y, int n, int m) {
    if (str_ary[x][y] == '.' && check_left(x, y, n, m) && check_right(x, y, n, m) && check_down(x, y, n, m)) {
        return true;
    }
    return false;
}

// 检查当前位置除了右方外是否都满足开垦条件
bool check_add_right(int x, int y, int n, int m) {
    if (str_ary[x][y] == '.' && check_left(x, y, n, m) && check_up(x, y, n, m) && check_down(x, y, n, m)) {
        return true;
    }
    return false;
}

// 检查当前位置除了左方外是否都满足开垦条件
bool check_add_left(int x, int y, int n, int m) {
    if (str_ary[x][y] == '.' && check_right(x, y, n, m) && check_up(x, y, n, m) && check_down(x, y, n, m)) {
        return true;
    }
    return false;
}

int main() {
    int n, m;
    std::cin >> n >> m;  // 输入地图大小
    // 输入地图数据
    for (int i = 0; i < n; i++) {
        std::cin >> str_ary[i];
    }
    int original_count = 0;  // 不清除杂物时可开垦的数量
    int add_count = 0;      // 清除一个杂物后额外增加的可开垦数量
    // 遍历地图的每个位置
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int temp_count = 0;  // 临时计数器
            if (str_ary[i][j] == '.') {  // 如果当前位置是荒地
                if (check_point(i, j, n, m)) {  // 检查是否可以开垦
                    original_count++;
                }
            } else {  // 如果当前位置是杂物
                // 检查清除当前杂物后，该位置是否可以开垦
                if (check_point(i, j, n, m)) {
                    temp_count++;
                }
                // 检查清除当前杂物后，周围的荒地是否可以开垦
                if (i != 0) {  // 检查上方
                    if (check_add_down(i - 1, j, n, m)) {
                        temp_count++;
                    }
                }
                if (i != n - 1) {  // 检查下方
                    if (check_add_up(i + 1, j, n, m)) {
                        temp_count++;
                    }
                }
                if (j != 0) {  // 检查左方
                    if (check_add_right(i, j - 1, n, m)) {
                        temp_count++;
                    }
                }
                if (j != m - 1) {  // 检查右方
                    if (check_add_left(i, j + 1, n, m)) {
                        temp_count++;
                    }
                }
            }
            // 更新清除杂物后能增加的最大开垦数量
            add_count = std::max(add_count, temp_count);
        }
    }
    // 输出总的可开垦数量
    std::cout << original_count + add_count;
    return 0;
}
