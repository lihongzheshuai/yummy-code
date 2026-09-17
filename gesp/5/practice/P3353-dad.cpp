#include <algorithm>
#include <iostream>

// 定义长整型别名，防止亮度累加溢出
typedef long long ll;

// 定义星星结构体，存储位置和亮度
struct Star {
    int x;      // 星星在数轴上的坐标
    int light;  // 星星的亮度
};

// 比较函数，用于按坐标 x 对星星进行升序排序
bool cmp(Star a, Star b) { return a.x < b.x; }

struct Star stars[100005];  // 存储所有星星的数组
int main() {
    int N, W;
    std::cin >> N >> W;
    for (int i = 0; i < N; i++) {
        std::cin >> stars[i].x >> stars[i].light;
    }
    // 将星星按位置坐标排序，方便使用滑动窗口
    std::sort(stars, stars + N, cmp);

    int start_idx = 0;  // 滑动窗口的左边界索引
    ll max_light = 0;   // 记录最大的亮度和
    ll cur_light = 0;   // 当前窗口内的亮度及

    // 双指针/滑动窗口主循环
    // i 代表窗口试图延伸到的右边界星星索引
    // start_idx 代表窗口当前的左边界星星索引
    for (int i = 0; i < N && start_idx < N;) {
        // 判断当前的星星 stars[i] 是否在以 stars[start_idx] 为起点的窗户范围内
        // 窗户宽度为 W，覆盖范围条件为：两星坐标差 + 1 <= W （即距离 <= W-1）
        // 这里的逻辑与样例输出即题目隐含的“窗户容量”相符
        if (stars[i].x - stars[start_idx].x + 1 <= W) {
            cur_light += stars[i].light;  // 如果在范围内，加上该星星亮度
            i++;                          // 右边界向右扩展
        } else {
            // 如果不在范围内，说明窗口需要向右移动，移除左边界星星
            cur_light -= stars[start_idx].light;
            start_idx++;  // 左边界向右收缩
        }
        // 每次变动后更新最大亮度记录
        max_light = std::max(max_light, cur_light);
    }
    std::cout << max_light << std::endl;
    return 0;
}