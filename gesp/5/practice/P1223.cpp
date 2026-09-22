/**
 * 题目: 【GESP/CSP练习】GESP五级 / CSP-J 题解：luogu-P1223 排队接水
 * 题号: P1223
 * 归属: GESP5级 / CSP-J
 * 博客: https://www.coderli.com/gesp-5-luogu-p1223-queue-water/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

// 定义结构体存储每个人的编号与接水耗时
struct Person {
    int id;    // 原始输入编号 (1 到 n)
    int time;  // 接水所需时间 t_i
};

// 自定义比较函数：按照接水时间从小到大升序排序
// 若接水时间相同，则严格按照原始输入编号从小到大排序 (稳定 tie-breaker)
// 严格遵循严格弱序 (Strict Weak Ordering)，绝不使用 <=
bool cmp(const Person& a, const Person& b) {
    if (a.time != b.time) {
        return a.time < b.time;
    }
    return a.id < b.id;
}

int main() {
    int n;
    cin >> n;

    // 创建 vector 存储 n 个排队人员的信息
    vector<Person> p(n);
    for (int i = 0; i < n; ++i) {
        p[i].id = i + 1; // 记录 1-indexed 原始编号
        cin >> p[i].time;
    }

    // 贪心策略：接水时间短的人优先服务
    // 根据排序不等式与微扰交换法，接水时间升序排列可使全局总等待时间严格最小
    sort(p.begin(), p.end(), cmp);

    // 统计所有人的总等待时间
    // 第 i 个人（0-indexed）接水时，排在他后面的 (n - 1 - i) 个人都在等待他
    // 因此第 i 个人的接水时间对总等待时间的贡献为 p[i].time * (n - 1 - i)
    // 极限情况下 1000 * 1000 / 2 * 10^6 ≈ 5 * 10^11，超出 32 位整型范围，必须使用 long long
    long long total_wait_time = 0;

    // 输出最优排队顺序（人的编号，空格分隔）
    for (int i = 0; i < n; ++i) {
        cout << p[i].id << (i == n - 1 ? "" : " ");
        total_wait_time += (long long)p[i].time * (n - 1 - i);
    }
    cout << endl;

    // 计算平均等待时间并保留两位小数
    double avg_wait_time = (double)total_wait_time / n;
    cout << fixed << setprecision(2) << avg_wait_time << endl;

    return 0;
}
