/**
 * Problem: luogu-P1059 [NOIP2006 普及组] 明明的随机数
 * Algorithm: 桶标记法 (Bucket Flagging · 空间换时间天然有序)
 * Standard: C++11 (CCF GESP 四级 / CSP-J 官方规范)
 * Author: OneCoder
 */

#include <iostream>

using namespace std;

// bucket[x] 记录数值 x 是否出现过
// 数值范围 1 ~ 1000，数组大小开 1005 预留安全边界
int bucket[1005];

int main() {
    int n;
    cin >> n;

    int distinct_cnt = 0; // 记录不重复的随机数个数

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        // 如果该数值之前未出现过，标记为已出现，且计数加 1
        if (bucket[x] == 0) {
            bucket[x] = 1;
            distinct_cnt++;
        }
    }

    // 第一行输出不重复的随机数总个数
    cout << distinct_cnt << "\n";

    // 第二行按照数值从小到大（下标 1 到 1000）依次扫描输出
    bool first = true;
    for (int v = 1; v <= 1000; ++v) {
        if (bucket[v] == 1) {
            if (!first) {
                cout << " ";
            }
            cout << v;
            first = false;
        }
    }
    cout << "\n";

    return 0;
}
