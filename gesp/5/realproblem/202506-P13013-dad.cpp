#include <cmath>
#include <iostream>

int main() {
    // 定义变量 n, m 分别表示小 A 持有的课堂优秀券和作业优秀券的数量
    // a, b 表示兑换一份奖品所需的两种券的数量
    int n, m, a, b;
    std::cin >> n >> m >> a >> b;

    // 为了方便贪心策略，将拥有的券数和兑换所需的券数都按大小排序
    // l1 为较多的券数，s1 为较少的券数
    int l1 = std::max(n, m);
    int s1 = std::min(n, m);
    // l2 为较大的兑换需求，s2 为较小的兑换需求
    int l2 = std::max(a, b);
    int s2 = std::min(a, b);

    int count = 0;  // 记录能兑换的奖品数量
    // 尝试进行循环兑换
    while (l1 >= 0 && s1 >= 0) {
        // 贪心策略：尝试用较多的券去填补较大的需求
        // 如果当前的券足够进行一次兑换（大对大，小对小）
        if (l1 >= l2 && s1 >= s2) {
            count++;   // 奖品数加一
            l1 -= l2;  // 扣除相应的券
            s1 -= s2;
        } else {
            // 如果不够兑换，则退出循环
            break;
        }
        // 每次兑换后，剩余的券数量可能会发生变化，导致 l1 不再是较大的那个
        // 所以需要重新检查并交换，确保 l1 始终大于等于 s1
        if (l1 < s1) {
            int tmp = l1;
            l1 = s1;
            s1 = tmp;
        }
    }
    // 输出最终兑换的奖品总数
    std::cout << count << std::endl;
    return 0;
}