/**
 * 题目: 【GESP】C++二级真题 luogu-b4007, [GESP202406 二级] 计数
 * 题号: B4007
 * 归属: GESP2级 (202406认证真题)
 * 博客: https://www.coderli.com/gesp-2-luogu-b4007/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include<iostream>
using namespace std;
int main(){
    int n, k, ans = 0; // 定义变量n、k和ans，ans初始化为0
    cin >> n >> k; // 从标准输入流中读取n和k的值
    for (int i = 1; i <= n; i++) { // 从1到n遍历每个整数
        int che = i; // 将当前整数赋值给che
        while (che != 0) { // 当che不为0时循环
            int z = che % 10; // 计算che除以10的余数，并赋值给z
            if (z == k) { // 如果z等于k
                ans++; // 将ans加1
            }
            che /= 10; // 将che除以10
        }
    }
    cout << ans; // 输出ans的值
    return 0; // 程序结束
}
