#include <iostream>
#include <vector>

struct Travel {
    int type; // 交通工具类型：0 代表地铁，1 代表公交车
    int cost; // 票价
    int time; // 乘车时间
};

int main() {
    int n; // 乘车记录的数量
    std::cin >> n;
    std::vector<Travel> travels; // 存储所有的出行记录
    std::vector<Travel> papers;  // 专门存储目前手里的地铁优惠券
    int total_cost = 0;          // 总花费金额
    
    // 读取所有的出行记录
    for (int i = 0; i < n; i++) {
        int type, cost, value;
        std::cin >> type >> cost >> value;
        travels.push_back(Travel{type, cost, value});
    }

    // 遍历计算每次出行的花费
    for (int i = 0; i < n; i++) {
        if (travels[i].type == 1) { // 如果这次乘坐的是公交车
            bool used = false; // 标记是否使用了优惠券
            // 遍历当前拥有的所有地铁优惠券
            for (int j = 0; j < papers.size(); j++) {
                // 条件1：优惠券要求的价格必须大于等于公交车票价
                // 条件2：公交车的时间减去地铁的时间必须在45分钟以内（即未超时）
                if (papers[j].cost >= travels[i].cost &&
                    papers[j].time + 45 >= travels[i].time) {
                    // 满足条件，使用这张优惠券
                    papers.erase(papers.begin() + j); // 从优惠券列表中删除它
                    used = true;
                    break; // 找到最早的一张满足条件的就直接跳出循环
                }
            }
            // 如果所有的优惠券都不能用，就需要自己花钱买公交车票
            if (!used) {
                total_cost += travels[i].cost;
            }
        } else { // 如果这次乘坐的是地铁
            total_cost += travels[i].cost; // 乘坐地铁必须花钱
            papers.push_back(travels[i]);  // 并且会获得一张相同价格和时间的优惠券
        }
    }

    std::cout << total_cost << std::endl;

    return 0;
}