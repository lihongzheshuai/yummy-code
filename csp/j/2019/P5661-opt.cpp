#include <iostream>

struct Ticket {
    int price; // 地铁票价（即优惠券可抵扣的最大金额）
    int time;  // 乘车时间
    bool used; // 标记该优惠券是否已经被公交车使用过
};

// 题目规定最多 10^5 条记录，所以开 100005 大小的数组足以存下所有的优惠券
Ticket papers[100005];

int main() {
    int n;
    std::cin >> n;
    
    int head = 0; // head 游标：指向当前时间下，最早获得且“还没过期”的优惠券
    int tail = 0; // tail 游标：每次获得新优惠券时存放的位置，就像排队的队尾
    
    long long total_cost = 0; // 记录总花费
    
    for (int i = 0; i < n; i++) {
        int type, price, time;
        std::cin >> type >> price >> time;
        
        if (type == 0) { // 如果乘坐的是地铁
            total_cost += price; // 地铁必定要花钱
            
            // 获得一张优惠券，保存在队尾 (tail)，然后让 tail 加 1
            papers[tail].price = price;
            papers[tail].time = time;
            papers[tail].used = false; // 刚获得的优惠券还没被使用
            tail++;
            
        } else { // 如果乘坐的是公交车
            
            // 【核心优化 1】滑动窗口思想，淘汰过期优惠券
            // 如果 head 指向的优惠券已经超过了 45 分钟，说明它永远也用不上了
            // 此时我们直接将 head 后移，这也就相当于“删除了”过期的优惠券
            // 因为题目保证给出的时间是递增排好序的，所以可以用 while 连续淘汰过期的优惠券
            while (head < tail && time - papers[head].time > 45) {
                head++;
            }
            
            bool used_coupon = false; // 记录这次公交车是否用上了优惠券
            
            // 【核心优化 2】控制循环次数
            // 从 head（没过期的最早的优惠券）向后遍历，找到能用的第一张
            // 这个循环看似是 for，但因为上面用 while 排除了大于 45 分钟的优惠券
            // 且题目说明“不会有两条记录在同一分钟”，所以这里 head 到 tail 之间的优惠券数量最多只有 45 张！
            // 所以即使 n 有 10 万次，每次公交车的 for 循环最多也只执行 45 次！不会超时。
            for (int j = head; j < tail; j++) {
                
                // 找到第一张没被用过，且价格足够抵扣公交车票价的优惠券
                if (!papers[j].used && papers[j].price >= price) {
                    papers[j].used = true; // 标记它已经被使用了
                    used_coupon = true;
                    break; // 按照题目要求，优先使用最早的（因为从 head 开始找，找到的必定是最早的），找到就立刻退出
                }
            }
            
            // 如果找了一圈发现没有合适的优惠券，只能自己掏钱买公交票了
            if (!used_coupon) {
                total_cost += price;
            }
        }
    }
    
    std::cout << total_cost << std::endl;
    return 0;
}
