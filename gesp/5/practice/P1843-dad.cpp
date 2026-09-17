#include <algorithm>
#include <cmath>
#include <iostream>

typedef long long ll;
ll w[500005];  // 存储每件衣服的湿度
int n, a, b;   // n: 衣服数量, a: 自然晒干速度, b: 烘干机额外烘干速度

// 检查函数：判断是否能在 mid 秒内晒干所有衣服
bool check(ll mid) {
    ll total_time = mid;  // 剩余可用的烘干机时间，初始为 mid 秒
    for (int i = 1; i <= n; i++) {
        // 如果这件衣服在 mid 秒内自然晒干就能干，则不需要烘干机
        if (w[i] <= mid * a) {
            continue;
        }

        // 计算扣除自然晒干 mid*a 后，还剩下的湿度
        ll need = w[i] - mid * a;

        // 剪枝：如果剩下的湿度连用满 mid 秒烘干机都干不了，直接返回不可行
        // 注意：这里不是必须的，但可以加速。烘干机每秒额外提供 b 点湿度消除
        if (need > mid * b) {
            return false;
        }

        // 计算需要烘干机多少秒才能消除剩余的 need 湿度
        // 使用整数向上取整公式 (need + b - 1) / b
        // 因为烘干机每秒额外贡献 b，加上原本的 a，总共是 a+b。
        // 这里只计算额外部分需要的时间，因为自然部分 mid*a 已经统一减去了。
        // 实际上，衣服 i 需要 t_i 时间烘干，mid - t_i 时间自然晒。
        // 总去湿 = t_i * (a+b) + (mid - t_i) * a = t_i * b + mid * a
        // 所以需要满足：t_i * b + mid * a >= w[i]
        // 也就是 t_i * b >= w[i] - mid * a
        // 即 t_i >= (w[i] - mid * a) / b
        ll time = (need + b - 1) / b;

        // 如果这件衣服需要的烘干时间超过了剩余可用时间，则 mid 秒不可行
        if (time > total_time) {
            return false;
        }

        // 扣除这件衣服占用的烘干机时间
        total_time -= time;
    }
    return true;  // 所有衣服都能在 mid 秒内干，且烘干机时间够分配
}

int main() {
    std::cin >> n >> a >> b;
    ll r = 0;  // 二分查找的上界
    for (int i = 1; i <= n; i++) {
        std::cin >> w[i];
        r = std::max(r, w[i]);  // 最坏情况：衣服全是自然晒干，需要 max(w[i]) /
                                // a 时间，粗略取 max(w[i]) 即可
    }

    ll l = 1;  // 二分查找的下界
    while (l <= r) {
        ll mid = l + (r - l) / 2;
        if (check(mid)) {
            // 如果 mid 秒可行，说明答案可能是 mid 或者更小
            r = mid - 1;
        } else {
            // 如果 mid 秒不可行，说明需要更多时间
            l = mid + 1;
        }
    }

    std::cout << l << std::endl;
    return 0;
}