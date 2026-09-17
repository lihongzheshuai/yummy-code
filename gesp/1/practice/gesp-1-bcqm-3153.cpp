/**
 * 题目: 【GESP】C++一级练习 bcqm-3153, 订餐时间
 * 题号: 
 * 归属: GESP1级
 * 博客: https://www.coderli.com/gesp-1-bcqm-3153/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;
int main() {
    // 输入火锅店的数量n
    int a;
    cin >> a;
    // 用于存储每段路程的时间
    int d;
    // 总时间
    int ans = 0;
    // 循环n次，累加每段路程的时间
    for (int i = 1; i <= a; i++) {
        cin >> d;
        ans += d;
    }
    // 输出总时间
    cout << ans;
    return 0;
}
