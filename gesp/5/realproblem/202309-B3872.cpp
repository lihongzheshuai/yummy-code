/**
 * 题目: 【GESP】C++五级真题（贪心考点） luogu-B3872 [GESP202309 五级] 巧夺大奖
 * 题号: B3872
 * 归属: GESP5级 (202309认证真题)
 * 博客: https://www.coderli.com/gesp-5-luogu-b3872/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <algorithm>
#include <cmath>
#include <iostream>

// 小游戏结构体：记录每个游戏的截止时间段与奖励
struct Game {
    int time;   // 该游戏必须在第 time 个时间段结束前完成
    int reward; // 完成该游戏可获得的奖励
};

// 全局数组：games 存储所有小游戏；game_count 标记某时间段是否已被占用
struct Game games[505];
int game_count[505]; // 0 表示该时间段空闲，1 表示已占用

// 排序比较函数：按 reward 降序，优先处理奖励高的游戏
bool cmp(Game a, Game b) { return a.reward > b.reward; }

int main() {
    int n;
    std::cin >> n; // 读取时间段（也是游戏）总数

    // 读取每个游戏的截止时间
    for (int i = 1; i <= n; i++) {
        std::cin >> games[i].time;
    }

    // 读取每个游戏的奖励
    for (int i = 1; i <= n; i++) {
        std::cin >> games[i].reward;
    }

    // 按奖励从高到低排序，贪心策略：优先安排奖励高的游戏
    std::sort(games + 1, games + n + 1, cmp);

    int result = 0; // 记录最终能获得的最大奖励

    // 遍历排好序的游戏，尝试将其放入最靠近截止时间的空闲段
    for (int i = 1; i <= n; i++) {
        // 从该游戏截止时间往前找，找到第一个空闲时间段
        // 核心贪心策略：奖励越高越优先安排，但要把游戏尽量往后“塞”
        // 从截止时间往前扫，找到第一个空闲时间段就占住，
        // 这样前面的时间段能留给截止时间更早的游戏，最大化总奖励。
        for (int j = games[i].time; j >= 1; j--) {
            if (game_count[j] == 0) { // 找到空闲段
                result += games[i].reward; // 累加奖励
                game_count[j] = 1;         // 标记该时间段已占用
                break;                     // 该游戏安排成功，跳出
            }
        }
    }

    std::cout << result; // 输出最高可获得的奖励
    return 0;
}
