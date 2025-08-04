#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// 定义最大位数，N 足够大以支持高精度乘法
const int N = 1e5 + 5;
int a[N], b[N], c[N];

int main() {
    string s1, s2;
    // 输入两个大整数（以字符串形式）
    cin >> s1 >> s2;

    // 获取两个字符串的长度
    int len1 = (int)s1.size();
    int len2 = (int)s2.size();

    // 将输入的字符串逆序存入数组 a 和 b
    // 这样最低位在数组下标 0，方便后续计算
    for (int i = 0; i < len1; i++) {
        a[i] = s1[len1 - 1 - i] - '0'; // 字符转数字并逆序
    }
    for (int i = 0; i < len2; i++) {
        b[i] = s2[len2 - 1 - i] - '0'; // 字符转数字并逆序
    }

    // 高精度乘法核心：逐位相乘并累加到结果数组 c
    // c[i + j] 存储 a[i] * b[j] 的结果
    for (int i = 0; i < len1; i++) {
        for (int j = 0; j < len2; j++) {
            c[i + j] += a[i] * b[j];
        }
    }

    // 处理进位
    // 如果某一位大于等于 10，则向高位进位
    int len = len1 + len2; // 结果最大长度
    for (int i = 0; i < len; i++) {
        if (c[i] >= 10) {
            c[i + 1] += c[i] / 10; // 进位到高一位
            c[i] %= 10;            // 当前位只保留个位数
        }
    }

    // 去除结果前导零（高位多余的 0）
    while (len > 1 && c[len - 1] == 0) {
        len--;
    }

    // 逆序输出最终结果（高位到低位）
    for (int i = len - 1; i >= 0; i--) {
        cout << c[i];
    }
    cout << endl;

    return 0;
}