/**
 * 题目: 【GESP】C++二级真题 luogu-B4260 [GESP202503 二级] 时间跨越
 * 题号: B4260
 * 归属: GESP2级 (202503认证真题)
 * 博客: https://www.coderli.com/gesp-2-luogu-b4260/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;

int main() {
    // 声明年、月、日、时、时间跨度变量
    int y, m, d, h, k;
    // 输入年月日时和时间跨度
    cin >> y >> m >> d >> h >> k;
    // 计算小时
    h += k;
    // 如果小时超过24，进位到天
    if (h >= 24) {
        h -= 24;
        d++;
    }
    // 处理日期进位
    if (d == 32) {
        // 大月进位
        d = 1;
        m++;
    } else if (d == 31 && (m == 4 || m == 6 || m == 9 || m == 11)) {
        // 小月进位（4,6,9,11月）
        d = 1;
        m++;
    } else if (d == 30 && m == 2) {
        // 2月进位（30天）
        d = 1;
        m++;
    } else if (d == 29 && m == 2 &&
               !(y % 400 == 0 || y % 4 == 0 && y % 100 != 0)) {
        // 2月进位（29天，非闰年）
        d = 1;
        m++;
    }
    // 处理月份进位到年
    if (m == 13) {
        m = 1;
        y++;
    }
    // 输出结果
    cout << y << " " << m << " " << d << " " << h << endl;
    return 0;
}
