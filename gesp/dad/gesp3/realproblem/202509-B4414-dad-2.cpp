#include <cstdio>
#include <iostream>

int month_days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main() {
    int m;
    std::cin >> m;
    std::cout << "MON TUE WED THU FRI SAT SUN\n";
    int start_day = 1;
    int total_days = 0;
    if (m == 9) {
        start_day = 1;
    } else if (m < 9) {
        for (int i = m; i < 9; i++) {
            total_days += month_days[i];
        }
        start_day = 7 - (total_days - start_day) % 7;
    } else {
        for (int i = 9; i < m; i++) {
            total_days += month_days[i];
        }
        start_day += total_days % 7;
    }
    for (int i = 1; i <= month_days[m] + start_day - 1; i++) {
        if (i < start_day) {
            std::cout << "   " << " ";
        } else {
            printf("% 3d ",i - start_day + 1);
        }
        if (i % 7 == 0) {
            std::cout << "\n";
        }
    }
    return 0;
}