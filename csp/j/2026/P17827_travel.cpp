#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// P17827 [CSP-J 2026] 旅游 (travel)
// 判断座位字母是否位于过道左侧（A、B、C 在过道左侧，D、F 在过道右侧）
bool is_left(char ch) {
    return ch == 'A' || ch == 'B' || ch == 'C';
}

int main() {
    string c1, s1, c2, s2;
    cin >> c1 >> s1 >> c2 >> s2;

    // 1. 是否在同一节车厢
    bool same_car = (c1 == c2);

    // 2. 是否在同一节车厢的同一排（座位号前两位为排号）
    bool same_row = same_car && (s1.substr(0, 2) == s2.substr(0, 2));

    // 3. 是否在同一节车厢的同一排，且位于过道的同一侧
    char seat1 = s1[2];
    char seat2 = s2[2];
    bool same_side = same_row && (is_left(seat1) == is_left(seat2));

    // 4. 两个座位是否相邻
    // 过道左侧序列为 A-B-C，字母ASCII码相差1即相邻；
    // 过道右侧序列仅 D-F 两个座位，题目保证两张票不是同一座位，只要同侧且不同即相邻
    bool adjacent = false;
    if (same_side) {
        if (is_left(seat1)) {
            adjacent = (abs(seat1 - seat2) == 1);
        } else {
            adjacent = (seat1 != seat2);
        }
    }

    cout << (same_car ? '1' : '0')
         << (same_row ? '1' : '0')
         << (same_side ? '1' : '0')
         << (adjacent ? '1' : '0') << endl;

    return 0;
}
