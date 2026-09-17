/**
 * 题目: 【GESP】C++二级练习 luogu-b3686, [语言月赛202212]  洛谷三角洲
 * 题号: B3686
 * 归属: GESP2级
 * 博客: https://www.coderli.com/gesp-2-luogu-b3686/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <cmath>
#include <iostream>

using namespace std;
int main() {
    int x, y, z; // 定义变量x, y, z
    cin >> x >> y >> z; // 从输入流中读取x, y, z的值
    cout << min(x, y + z) << endl; // 输出x和y+z的最小值
    cout << min(y, x + z) << endl; // 输出y和x+z的最小值
    cout << min(z, x + y) << endl; // 输出z和x+y的最小值
    return 0;
}
