#include <algorithm>
#include <iostream>
#include <vector>

// 题目：P1413 坚果保龄球
// 链接：https://www.luogu.com.cn/problem/P1413
// 核心思路：
// 使用贪心算法。对于每一行，我们将僵尸出现的时间进行排序。
// 首先放置一个坚果消灭第一个僵尸，这个坚果可以覆盖一定的时间范围（60秒内）。
// 如果下一个僵尸出现的时间完全在这个范围内，就不需要新的坚果。
// 否则，就需要放置一个新的坚果。

int main() {
    int n;
    // 读取僵尸的总数量
    std::cin >> n;

    // 创建一个大小为7的二维向量，实际上只使用索引 1 到 6，对应 6 行
    std::vector<std::vector<int>> v(7);

    // 读取每个僵尸的信息
    for (int i = 0; i < n; i++) {
        int row, time;
        std::cin >> row >> time;
        // 将僵尸出现的时间记录在对应的行中
        v[row].push_back(time);
    }

    // 对每一行僵尸出现的时间进行升序排序
    for (int i = 1; i <= 6; i++) {
        std::sort(v[i].begin(), v[i].end());
    }

    int count = 0;  // 记录总共需要的坚果数量

    // 遍历每一行
    for (int i = 1; i <= 6; i++) {
        std::vector<int> row = v[i];
        // 如果这一行有僵尸
        if (row.size() > 0) {
            count++;                 // 首先需要一个坚果来对付这一行的第一个僵尸
            int last_time = row[0];  // 记录上一次放置坚果的时间

            // 遍历这一行的其余僵尸
            for (int j = 1; j < row.size(); j++) {
                // 如果当前僵尸出现的时间与上一个坚果的时间差超过 59 秒
                // 说明上一个坚果已经失效（跑出地图），需要一个新的坚果
                // 地图宽度为60，坚果和僵尸相对运动或覆盖逻辑一般理解为一个坚果管辖
                // 60 秒的区间
                if (row[j] - last_time > 59) {
                    count++;
                    last_time = row[j];  // 更新最新放置坚果的时间
                }
            }
        }
    }

    // 输出最少需要的坚果数
    std::cout << count << std::endl;
    return 0;
}