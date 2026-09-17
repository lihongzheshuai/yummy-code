/**
 * 题目: 【GESP】C++三级练习 luogu-p1428, 小鱼比可爱
 * 题号: P1428
 * 归属: GESP3级
 * 博客: https://www.coderli.com/gesp-3-luogu-p1428/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;
int result[101];
int a[101];
int main() {
    int n; // 输入的鱼的数量
    cin >> n; // 读取输入的鱼的数量
    for (int i = 0; i < n; i++) {
        cin >> a[i]; // 读取每只鱼的可爱程度
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (a[j] < a[i]) {
                result[i]++; // 计算左边比当前鱼可爱程度小的鱼的数量
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << result[i] << " "; // 输出每只鱼左边比自己可爱程度小的鱼的数量
    }
    return 0;
}
