#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

// 定义数组最大长度，可以处理10^5位的大数
const int N = 1e5 + 10;
// 定义三个数组，分别存储被减数、减数和差
int a[N], b[N], c[N];

int main() {
    // 输入两个大整数字符串
    string s1, s2;
    cin >> s1 >> s2;

    // 判断大小，决定是否需要负号并交换
    bool negative = false;
    // 如果s1的位数小于s2，或位数相等但s1小于s2
    if (s1.size() < s2.size() || (s1.size() == s2.size() && s1 < s2)) {
        swap(s1, s2);     // 交换两个字符串
        negative = true;  // 标记结果需要加负号
    }

    // 获取两个字符串的长度
    int len1 = (int)s1.size();
    int len2 = (int)s2.size();

    // 逆序存入数组，将个位存在数组0号位置
    for (int i = 0; i < len1; i++) {
        a[i] = s1[len1 - 1 - i] - '0';  // 字符转数字需要减去字符'0'
    }
    for (int i = 0; i < len2; i++) {
        b[i] = s2[len2 - 1 - i] - '0';
    }

    // 逐位相减并处理借位
    for (int i = 0; i < len1; i++) {
        // 当前位相减，注意减数可能已经用完，用0补充
        c[i] = a[i] - (i < len2 ? b[i] : 0);
        
        // 如果当前位结果小于0，需要向高位借位
        if (c[i] < 0) {
            c[i] += 10;        // 当前位加10
            a[i + 1]--;        // 向高一位借1
        }
    }

    // 去除高位多余的零
    int len = len1;
    // 如果最高位是0且长度大于1，则继续去除
    while (len > 1 && c[len - 1] == 0) {
        len--;
    }

    // 输出结果
    if (negative) {
        cout << '-';  // 如果之前判断需要负号，先输出负号
    }
    // 从高位到低位输出结果
    for (int i = len - 1; i >= 0; i--) {
        cout << c[i];
    }
    cout << endl;

    return 0;
}