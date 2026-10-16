/**
 * Problem: luogu-P1012 [NOIP 1998 提高组] 拼数
 * Algorithm: 邻项交换贪心与自定义字符串拼接排序 (Adjacent-Swap Greedy & Custom String Sorting)
 * Standard: C++11 (CCF GESP 四级 / CSP-J 官方规范)
 * Author: OneCoder
 */

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n;
string s[25]; // 将每个正整数直接作为字符串读入和存储

/**
 * 自定义排序比较函数（邻项交换法）
 * @param a 第一个待比较的数字字符串
 * @param b 第二个待比较的数字字符串
 * @return 若 a 排在 b 前面拼出的数字更大，则返回 true
 */
bool cmp(const string& a, const string& b) {
    // 比较两种拼接顺序：a 在前 (a + b) 与 b 在前 (b + a)
    // 因为 a + b 和 b + a 的字符串长度完全相同，字典序大小完全等价于数值大小
    return a + b > b + a;
}

int main() {
    // 读取正整数的个数 n
    cin >> n;

    // 直接以字符串形式读取 n 个正整数
    for (int i = 1; i <= n; ++i) {
        cin >> s[i];
    }

    // 使用自定义比较函数 cmp 对字符串数组 s[1..n] 进行排序
    sort(s + 1, s + n + 1, cmp);

    // 按排序后的最优顺序依次拼接输出，组成最大的整数
    for (int i = 1; i <= n; ++i) {
        cout << s[i];
    }
    cout << "\n";

    return 0;
}
