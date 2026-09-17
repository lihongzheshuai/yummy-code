/**
 * 题目: 【GESP真题】GESP一级题解：luogu-B4573 [GESP202609 一级] 新龟兔赛跑
 * 题号: B4573
 * 归属: GESP1级 (202609认证真题)
 * 博客: https://www.coderli.com/gesp-1-luogu-b4573-turtle-rabbit/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

/**
 * Problem: luogu-B4573 [GESP202609 一级] 新龟兔赛跑
 * Standard: C++11 (CCF GESP 官方大纲推荐标准)
 * Author: OneCoder
 */

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    // 基础流加速
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 定义双精度浮点型变量，输入乌龟时间、兔子速度、兔子睡眠时间
    double turtle_time = 0.0;
    double rabbit_speed = 0.0;
    double rabbit_sleep = 0.0;

    if (!(cin >> turtle_time >> rabbit_speed >> rabbit_sleep)) {
        return 0;
    }

    // 常量定义：全程固定距离 1000.0
    const double DISTANCE = 1000.0;

    // 1. 计算兔子纯奔跑时间与总耗时
    double rabbit_run_time = DISTANCE / rabbit_speed;
    double rabbit_total_time = rabbit_run_time + rabbit_sleep;

    // 2. 第一行：判定胜负（时间短者获胜）
    if (turtle_time < rabbit_total_time) {
        cout << "turtle\n";
    } else if (rabbit_total_time < turtle_time) {
        cout << "rabbit\n";
    } else {
        cout << "tie\n";
    }

    // 3. 第二行：格式化输出兔子总耗时，保留两位小数
    cout << fixed << setprecision(2) << rabbit_total_time << "\n";

    return 0;
}
