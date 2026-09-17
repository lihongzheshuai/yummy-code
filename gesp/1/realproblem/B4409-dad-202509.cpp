#include <iostream>
#include <cstdio>

int main() {
    int x, y, n, p;
    std::cin >> x >> y >> n >> p;
    int plan_one = p >= x ? p - y : p;
    double plan_two = p / 10.0 * n;
    double result = plan_one > plan_two ? plan_two : plan_one;
    printf("%.2f", result);
    return 0;
}