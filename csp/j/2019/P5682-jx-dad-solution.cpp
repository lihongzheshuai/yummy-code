#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    // 提升 cin/cout 效率
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    if (!(cin >> n)) return 0;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    // 排序并利用 STL 的 unique 去重
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    
    int k = a.size();
    
    if (k < 2) {
        // 去重后不足 2 个数，不可能有次大值
        cout << -1 << "\n";
    } else if (k == 2) {
        // 只有 2 个不同的数 a[0], a[1] (a[1] > a[0])
        // 最大结果肯定是 a[1] % a[0] 吗？
        // 不是！最大结果是由 a[0] % a[1] 产生的 a[0]。
        // 因为 n >= 3 且去重后只有2个数，必定有重复数字，所以必然会有数字自己模自己得到 0。
        // 所以所有可能的余数集合为 {a[0], a[1] % a[0], 0}。
        // 由于 a[1] % a[0] < a[0]，严格最大值是 a[0]，剩下的候选者就是 a[1] % a[0] 和 0 的最大值（即 a[1] % a[0]）。
        cout << a[1] % a[0] << "\n";
    } else {
        // >= 3 个不同的数
        // 最大结果必定是第二大元素 a[k-2]（由 a[k-2] % a[k-1] 得到）
        // 严格次大结果只会出现在以下两个候选者中：
        // 1. 第三大元素 a[k-3]（由 a[k-3] % a[k-1] 得到）
        // 2. 最大元素模第二大元素的余数 a[k-1] % a[k-2]
        // 取这两者的最大值即为答案
        cout << max(a[k - 3], a[k - 1] % a[k - 2]) << "\n";
    }
    
    return 0;
}
