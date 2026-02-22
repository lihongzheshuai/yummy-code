#include <cstdio>

/**
 * 题目：P1163 银行贷款
 * 描述：计算贷款的月利率。已知贷款原值 w0，每月还款 w，还款月数 m。
 * 算法：二分查找 (Binary Search)
 *
 * 逻辑：
 * 假设月利率为 x。根据复利公式或按月模拟：
 * 第1个月末欠款：w0 * (1 + x) - w
 * 第2个月末欠款：(w0 * (1 + x) - w) * (1 + x) - w
 * ...
 * 我们需要找到一个 x，使得第 m 个月末的欠款正好为 0。
 *
 * 性质：
 * 利率越高，最终欠款越多（函数单调递增）。
 * 当利率为 0 时，最终欠款为 w0 - w * m。
 * 题目保证答案不超过 300% (即 x <= 3.0)。
 */

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