#include <iostream>

std::string str_ary[1005];
const int di[4] = {-1, 1, 0, 0};
const int dj[4] = {0, 0, -1, 1};
int bad_count_ary[1005][1005];
int cnt[1005][1005];
bool check(int x, int y, int n, int m) {
    if (x < 0 || x >= n || y < 0 || y >= m || str_ary[x][y] == '.') {
        return true;
    }
    return false;
}
bool check_point(int x, int y, int n, int m, int& bad_count) {
    for (int i = 0; i < 4; i++) {
        int nx = x + di[i];
        int ny = y + dj[i];
        if (!check(nx, ny, n, m)) {
            bad_count++;
        }
    }
    return bad_count > 0 ? false : true;
}
int main() {
    int n, m;
    std::cin >> n >> m;
    for (int i = 0; i < n; i++) {
        std::cin >> str_ary[i];
    }
    int original_count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int temp_count = 0;
            int bad_count = 0;
            if (str_ary[i][j] == '.' && check_point(i, j, n, m, bad_count)) {
                original_count++;
            }
            bad_count_ary[i][j] = bad_count;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (str_ary[i][j] == '.' && bad_count_ary[i][j] == 1) {
                for (int k = 0; k < 4; k++) {
                    int nx = i + di[k];
                    int ny = j + dj[k];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
                        str_ary[nx][ny] == '#')
                        cnt[nx][ny]++;
                }
            }
        }
    }
    int best = 0;
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
                        bad++;
                }
                if (bad == 0) {
                    gain++;    // 它自己也能开垦
                }
                best = std::max(best, gain);  // 更新最大增益
            }
        }
    }
    std::cout << original_count + best;
    return 0;
}