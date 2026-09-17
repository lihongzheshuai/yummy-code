/**
 * 题目: 【NOIP】1999真题解析 luogu-P1016 旅行家的预算 | GESP四、五、六级以上推荐练习
 * 题号: P1016
 * 归属: GESP6级
 * 解法: 解法 1 / 共 2 种解法
 * 博客: https://www.coderli.com/noi-p-1999-luogu-p1016/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

// 定义一个结构体表示沿途的站点
struct Station {
    double distance; // 距离起点的距离
    double price;    // 油价

    // 重载小于号，以便按距离对站点进行排序
    bool operator<(const Station& other) const {
        return distance < other.distance;
    }
};

int main() {
    double S, C, L, P0;
    int N;

    // 读入起点到终点距离、油箱容量、每升油行驶距离、起点油价和加油站数
    std::cin >> S >> C >> L >> P0 >> N;

    std::vector<Station> valid_stations;
    // 起点也是一个加油站（编号为 0）
    valid_stations.push_back({0.0, P0});

    for (int i = 0; i < N; ++i) {
        double d, p;
        std::cin >> d >> p;
        // 只保存位于起点和终点之间的有效加油站
        if (d < S) {
            valid_stations.push_back({d, p});
        }
    }
    // 终点可看作一个油价为 0 的站，这样能保证贪心时会优先开向终点
    valid_stations.push_back({S, 0.0});

    // 对所有的站点按距离起点的距离从小到大排序
    std::sort(valid_stations.begin(), valid_stations.end());

    double max_dist = C * L; // 满油状态下最多能行驶的距离
    double total_cost = 0.0; // 累计总花费
    double remain_gas = 0.0; // 当前油箱中剩余的油量

    int cur = 0; // 当前所在的站点索引
    int dest_idx = valid_stations.size() - 1; // 终点的索引

    while (cur < dest_idx) {
        int next_station = -1;
        int min_price_station = -1;
        double min_price = 1e9;

        // 在满油可达范围内寻找合适的下一站
        for (int i = cur + 1; i <= dest_idx && valid_stations[i].distance - valid_stations[cur].distance <= max_dist; ++i) {
            // 策略1：寻找第一个比当前站油价便宜的站点
            if (valid_stations[i].price < valid_stations[cur].price) {
                next_station = i;
                break; // 找到后直接打破循环，驶向第一家更便宜的站
            }
            // 策略2备用：如果没有更便宜的，记住可达范围内油价最便宜的站点
            if (valid_stations[i].price < min_price) {
                min_price = valid_stations[i].price;
                min_price_station = i;
            }
        }

        if (next_station != -1) {
            // 找到了更便宜的站点，只需买刚好能到那一站的油
            double gas_needed = (valid_stations[next_station].distance - valid_stations[cur].distance) / L;
            if (gas_needed > remain_gas) { // 如果剩下的油不够，才需要买油
                total_cost += (gas_needed - remain_gas) * valid_stations[cur].price;
                remain_gas = 0.0; // 到达下一站时油刚好用完（除了一开始剩下的部分刚好抵消）
            } else {
                remain_gas -= gas_needed; // 如果剩的油足够开过去，这里甚至不需要买油
            }
            cur = next_station;

        } else if (min_price_station != -1) {
            // 没有比当前更便宜的，说明当前油站是续航范围内最便宜的，果断加满！
            // 然后开过去可达范围内最便宜的那一站
            total_cost += (C - remain_gas) * valid_stations[cur].price;
            // 到达下一站后余下的油 = 新的满油状态 - 路上消耗的油
            remain_gas = C - (valid_stations[min_price_station].distance - valid_stations[cur].distance) / L;
            cur = min_price_station;

        } else {
            // 策略3：可达范围内没有任何站，直接抛锚死锁
            std::cout << "No Solution\n";
            return 0;
        }
    }

    // 输出保留两位小数的总体最低费用
    std::cout << std::fixed << std::setprecision(2) << total_cost << "\n";
    return 0;
}
