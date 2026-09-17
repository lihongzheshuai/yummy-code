#include <algorithm>
#include <iostream>

// 定义常量 MAXN，这里 2*10^5 是考虑到 N 的最大值 200,000。
// 这里的 10e5 可能被解析为 float, 虽然也能用但标准写法最好是 200005 或
// 2*100000。
const int MAXN = 200005;
long long num_ary[MAXN];  // 使用 long long 存储输入数组，防止溢出（根据数据范围
                          // 0 <= ai < 2^30）

int main() {
    // 禁用 C++ stdio 与 C stdio 的同步，加快 cin/cout 的速度
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long N, C;
    // 读取元素个数 N 和 目标差值 C
    if (!(std::cin >> N >> C)) return 0;  // 输入检查

    // 读取 N 个正整数到数组 num_ary 中
    for (int i = 0; i < N; i++) {
        std::cin >> num_ary[i];
    }

    // 将数组进行从小到大排序，这对于使用双指针方法或二分查找是必须的
    std::sort(num_ary, num_ary + N);

    // ans 用于存储满足条件的数对总数，可能会很大，所以用 long long
    long long ans = 0;

    // 初始化两个指针 l (left) 和 r (right)，都从 0 开始
    // 注意：这里的算法是对于每一个 num_ary[i] (作为 B)，寻找有多少个 num_ary[j]
    // (作为 A) 满足 A = B + C 也就是在数组中寻找范围 [l, r)
    // 使得其中的元素都等于 num_ary[i] + C
    int l = 0, r = 0;

    // 遍历每一个数作为 B (即 num_ary[i])
    for (int i = 0; i < N; i++) {
        long long target = num_ary[i] + C;  // 计算出需要寻找的目标值 A = B + C

        // 将 l 指针向右移动，直到指向第一个 >= target 的元素
        // 这里的 while 循环利用了单调性：随着 num_ary[i] 增大，target 也增大，l
        // 不需要回退
        while (l < N && num_ary[l] < target) {
            l++;
        }

        // 将 r 指针向右移动，直到指向第一个 > target 的元素
        // 同样利用单调性，r 也不需要回退
        while (
            r < N &&
            num_ary[r] <=
                target) {  // 注意这里是 <=，我们要找的是 > target 的第一个位置
            r++;
        }

        // 如果 l 指向的元素确实等于 target，那么区间 [l, r) 中的所有元素都等于
        // target 这些元素的个数即为 r - l，累加到答案中
        if (l < N && num_ary[l] == target) {
            ans += (r - l);
        }
    }

    // 输出最终满足条件的数对总数
    std::cout << ans << std::endl;

    return 0;
}