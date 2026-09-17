/**
 * 题目: 【GESP】C++二级练习 luogu-P5723 【深基4.例13】质数口袋
 * 题号: P5723
 * 归属: GESP2级
 * 博客: https://www.coderli.com/gesp-2-luogu-p5723/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <cmath>
#include <iostream>
using namespace std;
int main() {
    // 输入口袋承重上限L
    int L;
    cin >> L;
    // 计数器，记录质数个数
    int count = 0;
    // 当前质数和
    int sum = 0;
    // 从2开始遍历数字
    int cur_num = 2;
    while (true) {
        // 假设当前数字是质数
        bool is_prime = true;
        // 对大于3的数进行质数判断
        if (cur_num > 3) {
            // 只需要判断到平方根即可
            for (int i = 2; i <= sqrt(cur_num); i++) {
                // 如果能被整除，则不是质数
                if (cur_num % i == 0) {
                    is_prime = false;
                    break;
                }
            }
        }
        // 如果是质数，尝试放入口袋
        if (is_prime) {
            sum += cur_num;
            // 如果总和未超过承重，则输出该质数
            if (sum <= L) {
                cout << cur_num << endl;
                count++;
            } else {
                // 超过承重则输出质数总数并结束
                cout << count;
                break;
            }
        }
        // 继续检查下一个数
        cur_num++;
    }
    return 0;
}
