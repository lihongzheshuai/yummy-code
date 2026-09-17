#include <cmath>
#include <iostream>

int array[25][25][25];
int main() {
    int w, x, h;
    std::cin >> w >> x >> h;
    for (int i = 1; i <= w; i++) {
        for (int j = 1; j <= x; j++) {
            for (int k = 1; k <= h; k++) {
                array[i][j][k] = 1;
            }
        }
    }
    int q;
    std::cin >> q;
    int count = 0;
    for (int i = 0; i < q; i++) {
        int x1, y1, z1, x2, y2, z2;
        std::cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;

        for (int j = x1; j <= x2; j++) {
            for (int k = y1; k <= y2; k++) {
                for (int l = z1; l <= z2; l++) {
                    array[j][k][l] = 0;
                }
            }
        }
    }
    for (int j = 1; j <= w; j++) {
        for (int k = 1; k <= x; k++) {
            for (int l = 1; l <= h; l++) {
                count += array[j][k][l];
            }
        }
    }
    std::cout << count;
    return 0;
}