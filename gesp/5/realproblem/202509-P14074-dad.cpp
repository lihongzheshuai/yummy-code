#include <iostream>

typedef long long ll;

int main() {
    // 定义左右边界 l 和 r，使用 long long 防止溢出
    ll l, r;
    std::cin >> l >> r;

    // ans 用于存储区间 [l, r] 内所有“有趣的整数”之和
    ll ans = 0;

    // 遍历区间 [l, r] 中的每一个整数 i
    // 时间复杂度分析：
    // 外层循环执行 (r - l + 1) 次。
    // 内层 while 循环每次处理一个整数，执行次数为该整数的二进制位数，约为
    // log2(r)。 对于 r <= 10^9，log2(r) 约为 30。 总时间复杂度为 O((r - l) *
    // log r)。 当 r - l 很大（如 10^9）时，运算量约为 3 * 10^10，会超出通常 1
    // 秒（约 10^8 次运算）的时间限制，导致超时 (TLE)。
    // 该算法只能通过小数据范围的测试点 (40% 数据)。
    for (ll i = l; i <= r; i++) {
        int tmp = 0;  // tmp 用于记录当前整数 i 的二进制表示中 1 的个数
        ll num = i;   // 复制 i 到 num，以免修改循环变量 i

        // 计算 num 的二进制表示中 1 的个数
        while (num > 0) {
            // 如果 num 的最低位是 1 (即 num 是奇数)
            if (num & 1) {
                tmp++;
            }
            // 将 num 右移一位，相当于除以 2
            num >>= 1;
        }

        // 如果 1 的个数是奇数，则认为该整数是“有趣的”
        if (tmp % 2 == 1) {
            ans += i;  // 将该整数累加到总和 ans 中
        }
    }

    // 输出最终结果
    std::cout << ans << std::endl;
    return 0;
}