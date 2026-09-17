/**
 * 题目: 【GESP】C++二级练习 luogu-P4956 [COCI 2017/2018 \#6] Davor
 * 题号: P4956
 * 归属: GESP2级
 * 博客: https://www.coderli.com/gesp-2-luogu-p4956/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;
int main() {
    // 输入总金额n
    int n;
    cin >> n;
    // 初始化k为1（最小可能值）
    int k = 1;
    // 初始化x为100（题目要求的最大可能值）
    int x = 100;
    while(true) {
        // 根据等差数列求和公式计算k
        // 52周 * (7x + 21k) = n
        // 其中7x是每周基础金额之和，21k是每周增量金额之和
        double tmp_k = (n / 52 - 7 * x) /  21.0;
        // 如果k小于1，不符合题目要求，减小x继续尝试
        if (tmp_k < 1) {
            x--;
            continue;
        }
        // 将tmp_k转换为整数
        k = (int) tmp_k;
        // 如果k是整数（即tmp_k转换前后相等），说明找到了答案
        if (k == tmp_k) {
            cout << x << endl << k;
            break;
        } else {
            // 如果k不是整数，减小x继续尝试
            x--;
            continue;
        }
    }
    return 0;
}
