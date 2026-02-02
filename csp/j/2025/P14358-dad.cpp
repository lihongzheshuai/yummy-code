#include <algorithm>
#include <iostream>

int a[105];
int main() {
    int n, m;
    std::cin >> n >> m;
    for (int i = 1; i <= n * m; i++) {
        std::cin >> a[i];
    }
    int target = a[1];
    std::sort(a + 1, a + n * m + 1, std::greater<int>());
    int idx;
    for (int i = 1; i <= n * m; i++) {
        if (a[i] == target) {
            idx = i;
            break;
        }
    }
    int row, col;
    col = (idx - 1) / n + 1;
    row = (idx - 1) % n;
    if (col % 2 == 0) {
        row = n - row;
    } else {
        row += 1;
    }
    std::cout << col << " " << row;
    return 0;
}