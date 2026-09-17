#include <cstdio>
using namespace std;
int main() {
    double f;
    scanf("%lf", &f);
    double c;
    c = 5 * (f - 32) / 9;
    printf("%.5f", c);
    return 0;
}
