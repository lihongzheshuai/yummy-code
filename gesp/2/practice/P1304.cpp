/**
 * 题目: 【GESP】C++二级练习 luogu-P1304 哥德巴赫猜想
 * 题号: P1304
 * 归属: GESP2级
 * 博客: https://www.coderli.com/gesp-2-luogu-p1304/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <cmath>
#include <iostream>

using namespace std;
int main() {
    int n; // 读取输入的正偶数N
    cin >> n; // 从输入流中读取N的值
    for (int i = 4; i <= n; i += 2) { // 从4开始，到N结束，每次增加2
        int other = 0; // 初始化变量other，用于存储i减去j的结果
        for (int j = 2; j <= i / 2; j++) { // 从2开始，到i的一半结束
            bool flag = true; // 初始化标志位，用于判断j和other是否为质数
            other = i - j; // 计算i减去j的结果
            for (int k = 2; k <= sqrt(j); k++) { // 从2开始，到j的平方根结束
                if (j % k == 0) { // 如果j能被k整除，则j不是质数
                    flag = false; // 将标志位设置为false
                    break; // 跳出循环
                }
            }
            if (!flag) { // 如果j不是质数，则继续下一轮循环
                continue;
            } else { // 如果j是质数，则检查other是否为质数
                for (int k = 2; k <= sqrt(other); k++) { // 从2开始，到other的平方根结束
                    if (other % k == 0) { // 如果other能被k整除，则other不是质数
                        flag = false; // 将标志位设置为false
                        break; // 跳出循环
                    }
                }
            }
            if (flag) { // 如果j和other都是质数，则输出结果
                cout << i << "=" << j << "+" << other << endl; // 输出格式为i=j+other
                break; // 跳出循环
            }
        }
    }
    return 0; // 程序返回0，表示执行成功
}
