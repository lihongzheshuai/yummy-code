#include <iostream>

int nums[1000005];
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        std::cin >> nums[i];
    }
    // 二分查找：寻找第一个等于 q 的位置
    while (m--) {
        int q;
        std::cin >> q;
        int ans = -1;
        int l = 1, r = n;  // 初始化左右边界
        while (l <= r) {
            int mid = l + (r - l) / 2;  // 防止溢出的中间位置计算
            if (nums[mid] < q) {
                // 中间值小于目标值，说明目标在右半部分，且不包括 mid
                l = mid + 1;
            } else {
                // nums[mid] >= q
                if (nums[mid] == q) {
                    // 找到了一个等于 q 的值，记录位置
                    // 但我们要找的是 *第一个*，所以继续向左找
                    ans = mid;
                }
                // 即使找到了，也要向左收缩 r，尝试寻找更靠左的 q
                // 或者 nums[mid] > q，也需要向左收缩
                r = mid - 1;
            }
        }
        std::cout << ans << " ";
    }

    return 0;
}