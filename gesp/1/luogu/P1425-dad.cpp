#include <cstdio>
using namespace std;
int main() {
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    int start_m = a * 60 + b;
    int end_m = c * 60 + d;
    int cost_m = end_m - start_m;
    int cost_time_h = cost_m / 60;
    int cost_time_m = cost_m % 60;
    printf("%d %d", cost_time_h, cost_time_m);
    return 0;
}