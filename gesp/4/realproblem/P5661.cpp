/**
 * 题目: 【CSP】CSP-J 2019真题 | 公交换乘 luogu-P5661 （适合GESP四级及以上考生练习）
 * 题号: P5661
 * 归属: GESP4级
 * 博客: https://www.coderli.com/csp-j-2019-p5661/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>

// 定义优惠券结构体
struct Ticket {
    int price; // 地铁票价（可抵扣最大金额）
    int time;  // 乘车时间
    bool used; // 是否已被使用
};

Ticket tickets[100005]; // 存储所有获得的优惠票
int head = 0, tail = 0; // 模拟滑动窗口（队列）的头尾指针

int main() {
    int n;
    std::cin >> n;

    long long total_cost = 0; // 记录总花费，建议使用 long long 防爆 int

    for (int i = 0; i < n; i++) {
        int type, price, time;
        std::cin >> type >> price >> time;

        if (type == 0) {
            // 类型 0：乘坐地铁
            // 必然要花钱，花费累加
            total_cost += price;
            // 获得一张新优惠票，放入数组尾部并扩展 tail
            tickets[tail].price = price;
            tickets[tail].time = time;
            tickets[tail].used = false;
            tail++;
        } else {
            // 类型 1：乘坐公交车
            // 步骤 1：清理队头已经过期的旧优惠票，缩小查找范围
            // 如果 head 指向的票据已经越过了 45 分钟的有效期，直接淘汰不看
            while (head < tail && time - tickets[head].time > 45) {
                head++;
            }

            // 步骤 2：从队头开始（此时剩下的都是未过期的）向后遍历，找到恰好满足条件的票并使用
            bool found = false;
            for (int j = head; j < tail; j++) {
                // 如果当前优惠票未被使用，且抵用额度大于等于公交车票价
                if (!tickets[j].used && tickets[j].price >= price) {
                    tickets[j].used = true; // 标记为已使用
                    found = true;           // 标记找到了可用优惠票
                    break;                  // 题目要求优先使用最早获得的，故找到最早的一张立即退出
                }
            }

            // 步骤 3：如果刚才没找到符合条件的优惠券，那么只能原价乘公交车
            if (!found) {
                total_cost += price;
            }
        }
    }

    // 输出最终开销数字
    std::cout << total_cost << std::endl;
    return 0;
}
