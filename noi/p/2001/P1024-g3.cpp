#include <cstdio>
#include <iostream>

using namespace std;

double a, b, c, d;

// 计算方程 f(x) 的值
double f(double x) { return a * x * x * x + b * x * x + c * x + d; }

int main() {
    // 读取输入的系数
    scanf("%lf%lf%lf%lf", &a, &b, &c, &d);

    int count = 0;  // 记录找到的根的数量

    // 在 [-100, 100] 范围内枚举每一个长度为 1 的区间
    for (int i = -100; i < 100; i++) {
        double x1 = i;
        double x2 = i + 1;
        double y1 = f(x1);
        double y2 = f(x2);

        // 如果左端点 x1 是根
        if (y1 == 0) {
            printf("%.2lf ", x1);
            count++;
        }

        // 如果区间 (x1, x2) 内有根 (根据零点存在定理：f(x1) * f(x2) < 0)
        // 注意：如果 f(x1) == 0，这一步会跳过，避免重复输出
        // 如果 f(x2) == 0，这一步也会跳过，留给下一次循环的 f(x1) 处理
        else if (y1 * y2 < 0) {
            // 二分查找
            double l = x1;
            double r = x2;
            // 精度控制，一般比题目要求多 2-4 个数量级
            // 或者直接循环固定次数（如 100 次）也是一种常用技巧
            for (int k = 0; k < 100; k++) {
                double mid = (l + r) / 2;
                if (f(mid) * f(l) <= 0) {
                    r = mid;  // 根在 [l, mid]
                } else {
                    l = mid;  // 根在 [mid, r]
                }
            }
            printf("%.2lf ", l);
            count++;
        }

        // 已经找到 3 个根，可以提前退出
        if (count == 3) break;
    }

    // 特殊情况：如果最后一个根是 100，上面的循环只检查到了 99
    // 如果还没找齐 3 个根，检查一下 100
    if (count < 3 && f(100) == 0) {
        printf("%.2lf ", 100.00);
    }

    return 0;
}
