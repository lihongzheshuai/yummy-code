/**
 * 题目: 【GESP】C++五级练习题 luogu-P1163 银行贷款 | 二分答案和精密模拟
 * 题号: P1163
 * 归属: GESP5级
 * 解法: 解法 2 / 共 2 种解法
 * 博客: https://www.coderli.com/gesp-5-luogu-p1163/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <cstdio>

double w0, w;
int m;

/**
 * check 函数：根据猜测的利率 x，计算 m 个月后的剩余欠款。
 * @return 如果剩余欠款 > 0，返回 true (表示利率高了)；否则返回 false。
 */
bool check(double x) {
    double current_balance = w0;
    for (int i = 1; i <= m; i++) {
        // 每月结算：原欠款加上产生的利息，再减去当月还款额
        current_balance = current_balance * (1 + x) - w;
    }
    return current_balance > 0;
}

int main() {
    // 输入贷款原值、每月分期金额、总月数
    scanf("%lf %lf %d", &w0, &w, &m);

    // 二分搜索利率范围：从 0% 到 300%
    double left = 0, right = 3.0;

    // 进行 100 次迭代，足以保证极高精度（远超题目要求的 0.1%）
    for (int i = 0; i < 100; i++) {
        double mid = left + (right - left) / 2.0;
        if (check(mid)) {
            // 如果期末还有欠款，说明利息收多了，需要调低利率
            right = mid;
        } else {
            // 如果期末欠款已经清零或多还了，说明利率可能偏低
            left = mid;
        }
    }

    // 题目要求输出百分数，四舍五入到 0.1%
    // 例如：0.029 应该输出 2.9
    printf("%.1f\n", left * 100.0);

    return 0;
}
