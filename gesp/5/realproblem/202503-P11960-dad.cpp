#include <algorithm>
#include <iostream>
#include <vector>

// 定义全局数组存储小B和小C的出价，大小稍大于2*10^5
int b[200005];
int c[200005];

int main() {
    int n;
    // 输入n，物品总数为2n
    std::cin >> n;

    // 输入小B对2n件物品的出价
    for (int i = 0; i < 2 * n; i++) {
        std::cin >> b[i];
    }

    // 输入小C对2n件物品的出价
    for (int i = 0; i < 2 * n; i++) {
        std::cin >> c[i];
    }

    // diff数组存储每件物品卖给小B相比卖给小C的差价 (b[i] - c[i])
    std::vector<int> diff(2 * n);
    long long max_income = 0;

    for (int i = 0; i < 2 * n; i++) {
        // 计算差价
        diff[i] = b[i] - c[i];
        // 先假设所有物品都卖给小C，计算初始总收入
        max_income += c[i];
    }

    // 将差价从大到小排序
    // 差价越大，说明卖给小B越划算（或者亏得越少）
    std::sort(diff.begin(), diff.end(), std::greater<int>());

    // 贪心策略：选出差价最大的n件物品卖给小B
    // 将这n件物品的差价加到总收入中（相当于把这n件从卖给C改为卖给B）
    for (int i = 0; i < n; i++) {
        max_income += diff[i];
    }

    // 输出最大收入
    std::cout << max_income << std::endl;
    return 0;
}