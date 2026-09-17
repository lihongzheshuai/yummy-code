/**
 * 题目: 【GESP】C++二级真题 luogu-b3841, [GESP202306 二级] 自幂数判断
 * 题号: B3841
 * 归属: GESP2级 (202306认证真题)
 * 博客: https://www.coderli.com/gesp-2-luogu-b3841/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <cmath>
#include <iostream>

using namespace std;
int main() {
    int n; // 输入的整数个数
    cin >> n; // 读取输入的整数个数

    for (int i = 0; i < n; i++) { // 遍历每个输入的整数
        int m; // 当前输入的整数
        cin >> m; // 读取当前输入的整数
        int copy_m = m; // 复制当前输入的整数
        int pows = 0; // 计算当前输入的整数的位数
        while (copy_m != 0) { // 计算位数
            copy_m /= 10;
            pows++;
        }
        int sum = 0; // 计算每个位数的pows次方和
        copy_m = m; // 复制当前输入的整数
        while (copy_m != 0) { // 计算每个位数的pows次方和
            sum += pow(copy_m % 10, pows); // 计算当前位数的pows次方并累加
            copy_m /= 10; // 移除当前位数
        }
        if (sum == m) { // 判断是否为阿姆斯特朗数
            cout << "T" << endl; // 是阿姆斯特朗数输出T
        } else {
            cout << "F" << endl; // 不是阿姆斯特朗数输出F
        }
    }
    return 0;
}
