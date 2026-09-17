/**
 * 题目: 【GESP】C++五级练习 luogu-P3743 小鸟的设备
 * 题号: P3743
 * 归属: GESP5级
 * 博客: https://www.coderli.com/gesp-5-luogu-p3743/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 100005;

int n;
double p;
double a[MAXN], b[MAXN];

/**
 * @brief 检验在时间 T 内是否能够保证所有设备电量都不降为 0
 * @param T 目标运行时间（秒）
 * @return true 能量充足，可以坚持 T 秒
 * @return false 能量缺口过大，无法坚持 T 秒
 */
bool check(double T) {
    double total_need = 0.0;
    for (int i = 1; i <= n; i++) {
        // 如果自身初始能量不足以维持 T 秒的消耗
        if (a[i] * T > b[i]) {
            total_need += (a[i] * T - b[i]); // 累加该设备的能量缺口
        }
    }
    // 充电宝在 T 秒内最多能提供 p * T 的能量
    return total_need <= p * T;
}

int main() {
    // 优化标准 I/O 效率
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    if (!(cin >> n >> p)) return 0;

    double sum_a = 0.0; // 记录所有设备每秒总消耗能量速率
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
        sum_a += a[i];
    }

    // 1. 特判：充电功率大于等于总消耗速率，能够无限期使用
    if (sum_a <= p) {
        cout << -1 << "\n";
        return 0;
    }

    // 2. 实数二分答案
    double left = 0.0;
    double right = 1e11; // 设定一个足够大的二分上界

    // 固定迭代 100 次，区间缩小 2^(-100)，完全满足精度要求且杜绝死循环
    for (int iter = 0; iter < 100; iter++) {
        double mid = left + (right - left) / 2.0;
        if (check(mid)) {
            left = mid; // mid 秒可行，尝试寻找更大的时间
        } else {
            right = mid; // mid 秒不可行，缩小时间范围
        }
    }

    // 3. 高精度输出结果（保留 10 位小数以保证远低于 1e-4 的相对/绝对误差）
    cout << fixed << setprecision(10) << left << "\n";

    return 0;
}
