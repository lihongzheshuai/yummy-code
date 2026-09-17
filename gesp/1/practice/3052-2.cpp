/**
 * 题目: 【GESP】C++一级练习BCQM3052，鸡兔同笼
 * 题号: 3052
 * 归属: GESP1级
 * 解法: 解法 2 / 共 2 种解法
 * 博客: https://www.coderli.com/gesp-1-bcqm3052/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;
int main() {
    int x, y; // 声明 x: 头数, y: 脚数
    cin >> x >> y; // 输入总头数和总脚数
    int chicken, rabbit;
    // 假设全部是兔子，那么有 x * 4 只脚
    // 实际少出来的脚数 (x * 4 - y) 就是因为把鸡当成了兔子，每只鸡少 2 只脚
    chicken = (x * 4 - y) / 2;
    rabbit = x - chicken; // 兔子的数量为总头数减去鸡的数量
    cout << chicken << " " << rabbit; // 输出鸡和兔的数量
    return 0;
}
