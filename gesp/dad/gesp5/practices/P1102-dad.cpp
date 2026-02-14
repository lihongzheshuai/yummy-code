#include <algorithm>
#include <iostream>

// 使用 long long 防止溢出，C 的范围是 1 <= C < 2^30，A 和 B 同理
// 定义 long long 的别名 ll，方便编写
typedef long long ll;

// 全局数组，大小稍微开大一点防止越界
// N 最大 2*10^5
ll a[200005];

int main() {
    // 优化 I/O 操作速度
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    ll C;  // C 可能很大，用 ll
    std::cin >> N >> C;

    // 读取输入数组
    for (int i = 0; i < N; i++) {
        std::cin >> a[i];
    }

    // 排序是关键步骤。
    // A - B = C  =>  A = B + C
    // 排序后，对于确定的 B，我们可以二分查找 A (即 B + C)
    std::sort(a, a + N);

    ll ans = 0;
    // 遍历每一个数作为 B
    for (int i = 0; i < N; i++) {
        // 在 B 后面的位置寻找等于 B + C 的数的范围
        // lower_bound 返回第一个 >= (a[i] + C) 的位置
        // 注意：搜索范围 a + i + 1 到 a + N，因为 C >= 1，所以 A > B，A 一定在
        // B后面
        ll* start = std::lower_bound(a + i + 1, a + N, a[i] + C);

        // upper_bound 返回第一个 > (a[i] + C) 的位置
        ll* end = std::upper_bound(a + i + 1, a + N, a[i] + C);

        // 两个指针相减即为中间等于 a[i] + C 的元素个数
        // 如果找不到，start 和 end 会相等，结果为 0
        ans += (end - start);
    }

    // 输出结果
    std::cout << ans << std::endl;

    return 0;
}