#include <iostream>
#include <algorithm>
using namespace std;

// P17828 [CSP-J 2026] 回文串 (string)
// 核心算法：游程编码 (Run-Length Encoding, RLE) 压缩段上的双指针同步对齐消去

// 题目中连续段数量 n 最大为 2 * 10^5，预留冗余空间
const int MAXN = 200005;

// a[i] 表示第 i 段包含的连续相同字符的个数（由于单段长度可达 10^9，使用 long long 防止运算溢出）
long long a[MAXN];

// c[i] 表示第 i 段对应的小写英文字母
char c[MAXN];

int main() {
    // 读取连续段的总数量 n
    int n;
    cin >> n;

    // 依次读取每一段的长度 a[i] 和对应的字符 c[i]（下标从 1 到 n）
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> c[i];
    }

    // 定义双指针：
    // l 指向当前字符串最左端尚未匹配消耗完的段（初始为第 1 段）
    // r 指向当前字符串最右端尚未匹配消耗完的段（初始为第 n 段）
    int l = 1, r = n;

    // ans 累计最少需要修改的字符位置总数
    // 注意：总长度 L 最大可达 2 * 10^14，修改次数可能超过 int 范围，必须使用 long long
    long long ans = 0;

    // 当左指针 l 严格小于右指针 r 时，从首尾两端同时向中间成批对齐消去
    // 若循环進行到 l == r，说明只剩下最中间的同一段相同字符，其自身天然回文，无需任何修改
    while (l < r) {
        // 1. 计算当前左端第 l 段与右端第 r 段能够成批对齐匹配的最大长度 take
        long long take = min(a[l], a[r]);

        // 2. 判断首尾对称位置上的这 take 对字符是否相同：
        //    若字符不同（c[l] != c[r]），每一对对称位置都需要修改其中 1 个字符才能变成相同，因此累加 take 次修改
        if (c[l] != c[r]) {
            ans += take;
        }

        // 3. 将左端第 l 段和右端第 r 段的剩余未匹配长度同时扣减已匹配的 take 个字符
        a[l] -= take;
        a[r] -= take;

        // 4. 若左端第 l 段的字符已经全部匹配消耗完毕，左指针右移进入下一段
        if (a[l] == 0) {
            l++;
        }

        // 5. 若右端第 r 段的字符已经全部匹配消耗完毕，右指针左移进入前一段
        if (a[r] == 0) {
            r--;
        }
    }

    // 输出将原字符串修改为回文串所需的最少修改次数
    cout << ans << endl;

    return 0;
}
