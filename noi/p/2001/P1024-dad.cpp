#include <cstdio>
#include <iostream>

double a, b, c, d;

// 计算方程 f(x) 的值
double f(double x) { return a * x * x * x + b * x * x + c * x + d; }

int main() {
    // 禁用 I/O 同步，提高输入输出效率
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    // 读取输入的系数 a, b, c, d
    std::scanf("%lf %lf %lf %lf", &a, &b, &c, &d);

    // 在 [-100, 100] 范围内枚举每一个长度为 1 的区间
    for (int i = -100; i < 100; i++) {
        double x1 = i;      // 区间左端点
        double x2 = i + 1;  // 区间右端点
        double f1 = f(x1);  // 左端点函数值
        double f2 = f(x2);  // 右端点函数值

        // 如果左端点 x1 是根
        if (f1 == 0) {
            std::printf("%.2lf ", x1);
        }
        // 如果区间 (x1, x2) 内有根 (根据零点存在定理：f(x1) * f(x2) < 0)
        // 注意：如果 f(x1) == 0，这一步会跳过，避免重复输出
        // 如果 f(x2) == 0，这一步也会跳过，留给下一次循环的 f(x1) 处理
        else if (f1 * f2 < 0) {
            // 二分查找
            double l = x1;
            double r = x2;
            // 精度控制：直接循环固定次数（如 100 次）是一种常用且安全的技巧
            // 循环 100 次后，区间长度会缩小到 1/2^100，精度极高且不会死循环
            double ans = l;
            for (int k = 0; k < 100; k++) {
                double mid = l + (r - l) / 2;  // 计算中点
                // 如果 f(l) 和 f(mid) 异号，说明根在左半区间 [l, mid]
                if (f(l) * f(mid) <= 0) {
                    r = mid;
                } else {
                    // 否则根在右半区间 [mid, r]
                    l = mid;
                }
            }
            // 输出找到的根，保留两位小数
            std::printf("%.2lf ", r);
        }
    }
    return 0;
}
