#include <cstdio>
#include <iostream>

int main() {
    int m;
    std::cin >> m;
    std::cout << "MON TUE WED THU FRI SAT SUN\n";
    switch (m) {
        case 1:
            for (int i = 1; i <= 33; i++) {
                if (i <= 2) {
                    printf("    ");
                } else {
                    printf("% 3d ", i - 2);
                }
                if (i % 7 == 0) {
                    std::cout << "\n";
                }
            }
            break;
        case 2:
            for (int i = 1; i <= 33; i++) {
                if (i <= 5) {
                    printf("    ");
                } else {
                    printf("% 3d ", i - 5);
                }
                if (i % 7 == 0) {
                    std::cout << "\n";
                }
            }
            break;
        case 3:
            for (int i = 1; i <= 36; i++) {
                if (i <= 5) {
                    printf("    ");
                } else {
                    printf("% 3d ", i - 5);
                }
                if (i % 7 == 0) {
                    std::cout << "\n";
                }
            }
            break;
        case 4:
            for (int i = 1; i <= 31; i++) {
                if (i <= 1) {
                    printf("    ");
                } else {
                    printf("% 3d ", i - 1);
                }
                if (i % 7 == 0) {
                    std::cout << "\n";
                }
            }
            break;
        case 5:
            for (int i = 1; i <= 34; i++) {
                if (i <= 3) {
                    printf("    ");
                } else {
                    printf("% 3d ", i - 3);
                }
                if (i % 7 == 0) {
                    std::cout << "\n";
                }
            }
            break;
        case 6:
            for (int i = 1; i <= 36; i++) {
                if (i <= 6) {
                    printf("    ");
                } else {
                    printf("% 3d ", i - 6);
                }
                if (i % 7 == 0) {
                    std::cout << "\n";
                }
            }
            break;
        case 7:
            for (int i = 1; i <= 32; i++) {
                if (i <= 1) {
                    printf("    ");
                } else {
                    printf("% 3d ", i - 1);
                }
                if (i % 7 == 0) {
                    std::cout << "\n";
                }
            }
            break;
        case 8:
            for (int i = 1; i <= 35; i++) {
                if (i <= 4) {
                    printf("    ");
                } else {
                    printf("% 3d ", i - 4);
                }
                if (i % 7 == 0) {
                    std::cout << "\n";
                }
            }
            break;
        case 9:
            for (int i = 1; i <= 30; i++) {
                printf("% 3d ", i);
                if (i % 7 == 0) {
                    std::cout << "\n";
                }
            }
            break;
        case 10:
            for (int i = 1; i <= 33; i++) {
                if (i <= 2) {
                    printf("    ");
                } else {
                    printf("% 3d ", i - 2);
                }
                if (i % 7 == 0) {
                    std::cout << "\n";
                }
            }
            break;
        case 11:
            for (int i = 1; i <= 35; i++) {
                if (i <= 5) {
                    printf("    ");
                } else {
                    printf("% 3d ", i - 5);
                }
                if (i % 7 == 0) {
                    std::cout << "\n";
                }
            }
            break;
        case 12:
            for (int i = 1; i <= 31; i++) {
                printf("% 3d ", i);
                if (i % 7 == 0) {
                    std::cout << "\n";
                }
            }
            break;
        default:
            break;
    }
    return 0;
}