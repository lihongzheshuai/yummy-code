/**
 * 题目: 【GESP】C++二级真题 luogu-B4064 [GESP202412 二级] 寻找数字
 * 题号: B4064
 * 归属: GESP2级 (202412认证真题)
 * 博客: https://www.coderli.com/gesp-2-luogu-b4064/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <cmath>
#include <iostream>

using namespace std;
int main() {
    int n; // 读取测试数据的数量
    cin >> n;
    int a; // 读取正整数 a
    for (int i = 1; i <= n; i++) {
        cin >> a;
        bool flag = false; // 初始化标志位
        double c = sqrt(sqrt(a)); // 计算4次方根
        int d = (int)c; // 强转为整数
        if (pow(d, 4) == a) { // 检查是否满足条件
            flag = true; // 如果满足条件，则设置标志位为真
        }
        if (flag) {
            cout << d << endl; // 如果存在满足条件的正整数，则输出
        } else {
            cout << -1 << endl; // 否则输出 -1
        }
    }
    return 0;
}
