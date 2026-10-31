#include <iostream>
using namespace std;

// P17829 [CSP-J 2026] 按位与 (and)
// 核心算法：利用二进制高位权重的绝对优势，从最高位（第 29 位）到最低位（第 0 位）逐位贪心试填

// 题目中整数个数 n 最大为 2 * 10^5
const int MAXN = 200005;

// a[i] 存储小 R 拥有的第 i 个非负整数（0 <= a[i] < 2^30）
int a[MAXN];

int main() {
    // 读取非负整数的总个数 n 以及要求恰好选出的个数 m
    int n, m;
    cin >> n >> m;

    // 依次读取全部 n 个非负整数
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    // ans 记录当前已经贪心锁定“在最终按位与结果中必须为 1”的二进制位掩码，初始为 0
    int ans = 0;

    // 因为 0 <= a[i] < 2^30，所以二进制最高位为第 29 位（2^29）
    // 按照二进制位从高到低（29 -> 0）依次贪心试填：优先保证更高位为 1
    for (int bit = 29; bit >= 0; bit--) {
        // 1. 构造试填目标掩码 target：
        //    在保留前面已经成功锁定的所有高位 1（即 ans）的基础上，尝试将当前第 bit 位也置为 1
        int target = ans | (1 << bit);

        // 2. 统计原数组中能够同时满足 target 所有二进制 1 位的元素个数 cnt
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            // (a[i] & target) == target 成立，当且仅当 target 中所有为 1 的二进制位在 a[i] 中也全部为 1
            if ((a[i] & target) == target) {
                cnt++;
            }
        }

        // 3. 贪心决策：
        //    如果满足条件的候选数不少于 m 个（cnt >= m），说明既能保住之前锁定的所有高位 1，
        //    又能让当前第 bit 位在按位与结果中也变为 1，因此正式锁定该位，更新 ans = target；
        //    反之若 cnt < m，说明凑不够 m 个数，当前第 bit 位只能为 0，ans 保持不变
        if (cnt >= m) {
            ans = target;
        }
    }

    // 输出选出 m 个数按位与的最大结果
    cout << ans << endl;

    return 0;
}
