/**
 * 题目: 【GESP】C++二级练习 luogu-B3660, 集卡
 * 题号: B3660
 * 归属: GESP2级
 * 博客: https://www.coderli.com/gesp-2-luogu-b3660/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;
int main() {
    // 读取测试用例的数量
    int times;
    cin >> times;
    // 遍历每个测试用例
    for (int i = 0; i < times; i++) {
        // 读取卡牌的数量
        int count;
        cin >> count;
        // 初始化标志位
        bool flag = false;
        // 遍历每张卡牌
        for (int j = 0; j < count; j++) {
            // 读取卡牌的数字
            int n;
            cin >> n;
            // 如果卡牌的数字为0，设置标志位为true
            if (n == 0) {
                flag = true;
            }
        }
        // 根据标志位输出结果
        if (flag) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }
    // 返回0，表示程序正常结束
    return 0;
}
