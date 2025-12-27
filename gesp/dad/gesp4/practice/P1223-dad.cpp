#include <algorithm>
#include <iomanip>
#include <iostream>

typedef long long ll;
// 定义结构体Water，用于存储每个人的编号和接水时间
struct Water {
    int id;    // 人的编号
    int time;  // 接水所需时间
};

// 比较函数：按照接水时间从小到大排序
// 如果接水时间相同，则按照编号从小到大排序
bool cmp(Water a, Water b) {
    if (a.time == b.time) {
        return a.id < b.id;
    }
    return a.time < b.time;
}

struct Water t[1005];  // 数组大小大于1000，符合题目范围
int main() {
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        t[i].id = i;            // 记录初始编号
        std::cin >> t[i].time;  // 输入接水时间
    }
    // 贪心策略：接水时间越短的人排在越前面，能使后续所有人的等待时间总和最小
    std::sort(t + 1, t + n + 1, cmp);
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        std::cout << t[i].id << " ";
        // 计算总等待时间：
        // 第i个人接水时，排在他后面的 n-i 个人都在等待
        // 因此第i个人的时间贡献了 (n-i) 次等待
        sum += t[i].time * (n - i);
    }
    std::cout << "\n";
    // 输出平均等待时间，保留两位小数
    std::cout << std::setprecision(2) << std::fixed << (double)sum / n;
    return 0;
}