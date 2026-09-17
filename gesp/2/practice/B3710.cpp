/**
 * 题目: 【GESP】C++二级练习 luogu-B3710 [语言月赛202302] 破碎的历史
 * 题号: B3710
 * 归属: GESP2级
 * 博客: https://www.coderli.com/gesp-2-luogu-b3710/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include<iostream>
using namespace std;
int main() {
    // 定义浮点数S用于存储输入
    double S;
    cin >> S;
    // 将小数转换为整数便于计算
    int target = S * 100000000;
    // 用于统计满足条件的方案数
    int count = 0;
    // 四重循环遍历所有可能的组合
    for (int i = 0; i <= 100; i++) {
        for (int j = 0; j <= 100; j++) {
            for (int k = 0; k <= 100; k++) {
                for (int l = 0; l <= 100;l++) {
                    // 判断当前组合是否满足条件
                    if ((100 - i) * (100 - j) * (100 -k) * (100 - l)== target) {
                        count++;
                    }
                }
            }
        }
    }
    // 输出结果
    cout << count;
    return 0;
}
