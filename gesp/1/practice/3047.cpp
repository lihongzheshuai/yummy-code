/**
 * 题目: 【GESP】C++一级练习BCQM3047，浮点计算，四舍五入
 * 题号: 3047
 * 归属: GESP1级
 * 博客: https://www.coderli.com/gesp-1-bcqm3047/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;

int main() {
    int x;
    cin >> x; // 输入机票原价

    double z;
    cin >> z; // 输入折扣率

    double temp_price;
    // 计算打折后的金额
    // 注意 z 是折扣（例如 7.7 折是 0.77 倍），所以要除以 10
    temp_price = x * z / 10;

    int temp;
    // 核心逻辑：四舍五入到十位
    // 技巧：先除以 10，加上 0.5 利用整数强制转换实现四舍五入，再乘回 10
    temp = temp_price / 10 + 0.5;

    cout << temp * 10; // 输出最终整十的结果

    return 0;
}
