#include <iostream>

std::string str_ary[1005];

bool check_left(int x, int y, int n, int m) {
    if (y == 0) {
        return true;
    }
    if (str_ary[x][y - 1] == '.') {
        return true;
    }
    return false;
}

bool check_right(int x, int y, int n, int m) {
    if (y == m - 1) {
        return true;
    }
    if (str_ary[x][y + 1] == '.') {
        return true;
    }
    return false;
}

bool check_up(int x, int y, int n, int m) {
    if (x == 0) {
        return true;
    }
    if (str_ary[x - 1][y] == '.') {
        return true;
    }
    return false;
}

bool check_down(int x, int y, int n, int m) {
    if (x == n - 1) {
        return true;
    }
    if (str_ary[x + 1][y] == '.') {
        return true;
    }
    return false;
}

bool check_point(int x, int y, int n, int m) {
    if (check_left(x, y, n, m) && check_right(x, y, n, m) && check_up(x, y, n, m) && check_down(x, y, n, m)) {
        return true;
    }
    return false;
}

bool check_add_down(int x, int y, int n, int m) {
    if (str_ary[x][y] == '.' && check_left(x, y, n, m) && check_right(x, y, n, m) && check_up(x, y, n, m)) {
        return true;
    }
    return false;
}

bool check_add_up(int x, int y, int n, int m) {
    if (str_ary[x][y] == '.' && check_left(x, y, n, m) && check_right(x, y, n, m) && check_down(x, y, n, m)) {
        return true;
    }
    return false;
}

bool check_add_right(int x, int y, int n, int m) {
    if (str_ary[x][y] == '.' && check_left(x, y, n, m) && check_up(x, y, n, m) && check_down(x, y, n, m)) {
        return true;
    }
    return false;
}

bool check_add_left(int x, int y, int n, int m) {
    if (str_ary[x][y] == '.' && check_right(x, y, n, m) && check_up(x, y, n, m) && check_down(x, y, n, m)) {
        return true;
    }
    return false;
}

int main() {
    int n, m;
    std::cin >> n >> m;
    for (int i = 0; i < n; i++) {
        std::cin >> str_ary[i];
    }
    int original_count = 0;
    int add_count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int temp_count = 0;
            if (str_ary[i][j] == '.') {
                if (check_point(i, j, n, m)) {
                    original_count++;
                }
            } else {
                if (check_point(i, j, n, m)) {
                    temp_count++;
                }
                if (i != 0) {
                    if (check_add_down(i - 1, j, n, m)) {
                        temp_count++;
                    }
                }
                if (i != n - 1) {
                    if (check_add_up(i + 1, j, n, m)) {
                        temp_count++;
                    }
                }
                if (j != 0) {
                    if (check_add_right(i, j - 1, n, m)) {
                        temp_count++;
                    }
                }
                if (j != m - 1) {
                    if (check_add_left(i, j + 1, n, m)) {
                        temp_count++;
                    }
                }
            }
            add_count = std::max(add_count, temp_count);
        }
    } 
    std::cout << original_count + add_count;
    return 0;
}