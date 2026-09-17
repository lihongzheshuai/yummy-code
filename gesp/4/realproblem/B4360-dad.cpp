#include <iostream>

std::string str_ary[105];
int main() {
    int h, w;
    std::cin >> h >> w;
    int x1, x2, y1, y2;
    std::cin >> x1 >> x2 >> y1 >> y2;

    for (int i = 1; i <= h; i++) {
        std::cin >> str_ary[i];
    }

    for (int i = x1; i <= x2; i++) {
        for (int j = y1; j <= y2; j++) {
            std::cout << str_ary[i][j - 1];
        }
        std::cout << "\n";
    }
    return 0;
}