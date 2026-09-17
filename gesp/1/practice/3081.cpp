/**
 * 题目: 【GESP】C++一级练习BCQM3081，偶数
 * 题号: 3081
 * 归属: GESP1级
 * 博客: https://www.coderli.com/gesp-1-bcqm3081/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream> // 引入标准输入输出流库
using namespace std; // 使用标准命名空间

int main() {
    int a; // 声明一个整型变量 a
    cin >> a; // 读取输入的正整数 a
    
    // 判断 a 除以 2 的余数是否为 0，即判断 a 是否为偶数
    if (a % 2 == 0) {
        cout << "yes"; // 如果是偶数，输出 yes
    }
    
    return 0; // 程序正常结束
}
