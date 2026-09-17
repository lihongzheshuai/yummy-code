/**
 * 题目: 【NOIP】1999真题解析 luogu-P1016 旅行家的预算 | GESP四、五、六级以上推荐练习
 * 题号: P1016
 * 归属: GESP6级
 * 解法: 解法 2 / 共 2 种解法
 * 博客: https://www.coderli.com/noi-p-1999-luogu-p1016/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

struct Station {
    double distance; // 距离起点的距离
    double price;    // 油价

    // 重载小于号，以便按距离对站点进行排序
    bool operator<(const Station& other) const {
        return distance < other.distance;
    }
};

double S, C, L, P0; // 起点到终点距离、油箱容量、每升油行驶距离、起点油价
int N;              // 加油站数
std::vector<Station> valid_stations;
double max_dist;    // 满油状态下最多能行驶的距离

// 递归贪心求解
// 参数 cur: 当前在哪个站的索引
// 参数 remain_gas: 当前油箱中剩余的油量
// 参数 current_cost: 走到目前为止已经产生的累计花费
void dfs(int cur, double remain_gas, double current_cost) {
    // 递归终止条件：如果已经到达了最后一个站点（终点）
    if (cur == valid_stations.size() - 1) {
        // 打印最终的累计花费并结束递归，由于贪心选择的唯一性，这就是最优解
        std::cout << std::fixed << std::setprecision(2) << current_cost << "\n";
        return;
    }

    int next_station = -1;       // 记录策略1：第一个比当前便宜的油站编号
    int min_price_station = -1;  // 记录策略2：可达范围内的相对最便宜油站编号
    double min_price = 1e9;      // 用于维护相对最低价
    int dest_idx = valid_stations.size() - 1;

    // 在满油可达范围内寻找合适的下一站（查找逻辑与循环迭代完全一致）
    for (int i = cur + 1; i <= dest_idx && valid_stations[i].distance - valid_stations[cur].distance <= max_dist; ++i) {
        if (valid_stations[i].price < valid_stations[cur].price) {
            next_station = i; // 寻找第一个比当前站油价便宜的站点
            break;
        }
        if (valid_stations[i].price < min_price) {
            min_price = valid_stations[i].price; // 记录可达范围内油价最便宜的站点
            min_price_station = i;
        }
    }

    if (next_station != -1) {
        // 策略1：找到了更便宜的站点，只需买刚好能到那一站的油
        double gas_needed = (valid_stations[next_station].distance - valid_stations[cur].distance) / L;
        if (gas_needed > remain_gas) {
            // 如果剩余的油不够跑过去，需要补差价所需的油
            // 此时到达下一站后，油刚好耗尽为 0
            dfs(next_station, 0.0, current_cost + (gas_needed - remain_gas) * valid_stations[cur].price);
        } else {
            // 如果底油足够跑过去，不需要花钱买油，直接沿用以前的花费
            // 抵达下一站后，剩余的油等于现在的油扣减所需油量
            dfs(next_station, remain_gas - gas_needed, current_cost);
        }
    } else if (min_price_station != -1) {
        // 策略2：没有比当前更便宜的，说明当前油站是续航范围内最便宜的，果断加满！
        // 计算在当前这站加满所需的额外费用
        double cost_added = (C - remain_gas) * valid_stations[cur].price;
        // 计算抵达那一站后，扣去路上消耗，油箱里还会剩下多少油
        double gas_left = C - (valid_stations[min_price_station].distance - valid_stations[cur].distance) / L;
        // 让这两个新状态伴随递归深入
        dfs(min_price_station, gas_left, current_cost + cost_added);
    } else {
        // 策略3：可达范围内没有任何站，直接抛锚死锁
        std::cout << "No Solution\n";
    }
}

int main() {
    // 读入数据
    std::cin >> S >> C >> L >> P0 >> N;

    // 起点也是一个加油站（编号为 0）
    valid_stations.push_back({0.0, P0});
    for (int i = 0; i < N; ++i) {
        double d, p;
        std::cin >> d >> p;
        // 过滤掉终点之外的无效站
        if (d < S) {
            valid_stations.push_back({d, p});
        }
    }
    // 把终点标记为一个价格为 0 的站
    valid_stations.push_back({S, 0.0});

    // 所有合法站进行排序
    std::sort(valid_stations.begin(), valid_stations.end());
    max_dist = C * L; // 计算满油最大续航

    // 开启递归推演：
    // 从起点 0 出发，初始剩余油量为 0，初始花费为 0
    dfs(0, 0.0, 0.0);

    return 0;
}
