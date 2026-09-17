/**
 * 题目: 【GESP】C++二级真题 luogu-B3836, [GESP202303 二级] 百鸡问题
 * 题号: B3836
 * 归属: GESP2级 (202303认证真题)
 * 博客: https://www.coderli.com/gesp-2-luogu-b3836/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;
int main() {
    int x, y, z, n, m;
    cin >> x >> y >> z >> n >> m; // 读取输入的x, y, z, n, m
    int count = 0; // 初始化计数器
    for (int i = 0; i <= 1000; i++) { // 外层循环控制公鸡数量
        for (int j = 0; j <= 1000; j++) { // 内层循环控制母鸡数量
            int chick_num = m - i - j; // 计算小鸡数量
            if (chick_num >= 0 && chick_num % z == 0 && i* x + j* y + chick_num / z == n) { // 如果小鸡数量大于等于0且能被z整除且满足条件
                count++; // 计数器加1
            }
        }
    }
    cout << count; // 输出结果
    return 0; // 返回0，表示程序正常结束
}
