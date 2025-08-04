#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// 定义数组最大长度
const int N = 1e5 + 10;
// 定义三个数组分别存储两个加数和结果
int a[N] = {0}, b[N] = {0}, c[N] = {0};

int main() {
    // 输入两个大整数字符串
    string s1, s2;
    cin >> s1 >> s2;

    // 获取两个字符串的长度
    int len1 = (int)s1.size();
    int len2 = (int)s2.size();

    // 将第一个数字反向存入数组a，个位存在a[0]
    for (int i = 0; i < len1; i++) {
        a[i] = s1[len1 - 1 - i] - '0';
    }
    
    // 将第二个数字反向存入数组b，个位存在b[0]
    for (int i = 0; i < len2; i++) {
        b[i] = s2[len2 - 1 - i] - '0';
    }

    // 取两个数字的最大长度
    int maxLen = max(len1, len2);
    // 进位标志
    int carry = 0;
    
    // 从低位到高位逐位相加
    for (int i = 0; i < maxLen; i++) {
        // 当前位相加结果，包含进位
        int temp = a[i] + b[i] + carry;
        // 当前位保存个位数
        c[i] = temp % 10;
        // 更新进位
        carry = temp / 10;
    }
    
    // 处理最高位的进位
    if (carry) {
        c[maxLen++] = carry;
    }

    // 从高位到低位输出结果
    for (int i = maxLen - 1; i >= 0; i--) {
        cout << c[i];
    }
    cout << endl;

    return 0;
}