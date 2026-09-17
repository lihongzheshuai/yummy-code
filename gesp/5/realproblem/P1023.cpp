/**
 * 题目: 【NOIP】2000真题解析 luogu-P1023 税收与补贴问题（适合GESP四、五级以上练习）
 * 题号: P1023
 * 归属: GESP5级
 * 博客: https://www.coderli.com/noip-2000-luogu-p1023/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

int main() {
    // ========== 第一步：读取输入 ==========

    int ep; // 政府预期价格（希望商家以此价格销售）
    std::cin >> ep;

    int cost, s0; // cost: 商品成本价, s0: 以成本价销售时的销量
    std::cin >> cost >> s0;

    // 读取所有已知的 (价格, 销量) 数据点，存入 pts 数组
    // 首先将 (成本价, 成本价销量) 作为第一个数据点加入
    std::vector<std::pair<int, int>> pts;
    pts.push_back({cost, s0});

    // 循环读取后续数据点，直到遇到 (-1, -1) 终止标记
    int p, s;
    while (std::cin >> p >> s && !(p == -1 && s == -1)) {
        pts.push_back({p, s});
    }

    int dec; // 超过已知最高价位后，每升高一元钱，销量减少的数量
    std::cin >> dec;

    // ========== 第二步：构建销量函数 ==========

    // 将数据点按价格从小到大排序，方便后续线性插值
    std::sort(pts.begin(), pts.end());

    int maxP = pts.back().first;   // 已知数据点中的最高价位
    int maxS = pts.back().second;  // 最高价位对应的销量

    // 特判：若超过最高价位后销量不减少(dec=0)，且最高价位仍有销量
    // 则意味着价格可以无限上涨而销量不变，利润可以无限增长
    // 此时无论 t 取何值，总有更高价格的利润更大，预期价永远无法最优 → 无解
    if (dec == 0 && maxS > 0) {
        std::cout << "NO SOLUTION" << std::endl;
        return 0;
    }

    // getSales(price): 分段线性函数，计算任意整数价格 price 处的销量
    // 分三种情况：
    //   1. price < cost → 不允许低于成本销售，销量为 0
    //   2. price 在已知数据点范围内 → 相邻数据点之间做线性插值
    //   3. price > maxP → 超出最高价位，按 dec 递减，最低为 0
    auto getSales = [&](int price) -> int {
        // 低于成本价，不可销售
        if (price < cost) return 0;

        // 超过已知最高价位，按固定速率递减
        // 例如 maxP=31, maxS=110, dec=15，则 price=33 时销量 = 110 - 15*(33-31) = 80
        if (price > maxP) {
            int v = maxS - dec * (price - maxP);
            return v > 0 ? v : 0; // 销量不能为负
        }

        // 在已知数据点之间，找到 price 所在的区间并线性插值
        // 例如数据点 (28,130) 和 (30,120)，则 price=29 时：
        //   销量 = 130 + (29-28) * (120-130) / (30-28) = 130 + (-10)/2 = 125
        for (int i = 0; i + 1 < (int)pts.size(); i++) {
            if (price >= pts[i].first && price <= pts[i + 1].first) {
                int x1 = pts[i].first, y1 = pts[i].second;     // 左端点
                int x2 = pts[i + 1].first, y2 = pts[i + 1].second; // 右端点
                if (x1 == x2) return y1; // 两个数据点价格相同（退化情况）
                // 线性插值公式：y1 + (price - x1) * (y2 - y1) / (x2 - x1)
                // 使用 long long 防止中间乘法溢出
                return y1 + (long long)(price - x1) * (y2 - y1) / (x2 - x1);
            }
        }
        return maxS; // 理论上不会执行到这里
    };

    // ========== 第三步：推导 t 的约束范围 ==========

    int se = getSales(ep); // 预期价格处的销量
    int de = ep - cost;     // 预期价格与成本的差（即无税/补贴时的单位利润）

    // 计算需要检查的最高价格（销量仍然 > 0 的最高整数价格）
    // 例如 maxP=31, maxS=110, dec=15 → topPrice = 31 + (110-1)/15 = 31 + 7 = 38
    // 价格 38 处销量 = 110 - 15*7 = 5 > 0，价格 39 处销量 = 110 - 15*8 = -10 < 0
    int topPrice = maxP;
    if (dec > 0 && maxS > 0) {
        topPrice = maxP + (maxS - 1) / dec;
    }

    // lo 和 hi 分别记录 t 的下界和上界
    // 初始化为极小值和极大值（除以 2 防止后续运算溢出）
    long long lo = LLONG_MIN / 2; // t 的下界（t >= lo）
    long long hi = LLONG_MAX / 2; // t 的上界（t <= hi）
    bool noSol = false;           // 是否已确定无解

    // 遍历所有有效价格 pr（从成本价到最高有效价格）
    // 对于每个竞争价格 pr，推导出对 t 的约束
    for (int pr = cost; pr <= topPrice && !noSol; pr++) {
        if (pr == ep) continue; // 跳过预期价格本身
        int sp = getSales(pr);
        if (sp <= 0) continue;  // 销量 <= 0 的价格无利润，不构成竞争威胁
        int dp = pr - cost;     // 该价格与成本的差

        // 核心不等式：(de + t) * se >= (dp + t) * sp
        // 展开后移项：t * (se - sp) >= dp * sp - de * se
        // 记 diff = se - sp, numer = dp * sp - de * se
        // 则约束为：diff * t >= numer
        long long numer = (long long)dp * sp - (long long)de * se;
        int diff = se - sp;

        if (diff == 0) {
            // 情况 C：预期价格与竞争价格的销量完全相同
            // 此时约束退化为 0 * t >= numer，即 numer <= 0
            // 若 numer > 0，意味着无论 t 取何值，竞争价格的利润都更高 → 无解
            if (numer > 0) noSol = true;
        } else if (diff > 0) {
            // 情况 A：预期价格的销量更高（se > sp，通常 pr > ep）
            // 不等号方向不变：t >= numer / diff
            // 取整数下界：t >= ceil(numer / diff)
            long long bound;
            if (numer >= 0) {
                // 正数除正数，向上取整：(numer + diff - 1) / diff
                bound = (numer + diff - 1) / diff;
            } else {
                // 负数除正数，C++ 整数除法自动向零取整，即为向上取整
                bound = -((-numer) / diff);
            }
            lo = std::max(lo, bound); // 更新 t 的下界
        } else {
            // 情况 B：预期价格的销量更低（se < sp，通常 pr < ep）
            // diff < 0，除以负数不等号反向：t <= numer / diff
            // 将分子分母同时取反，转化为正除数：t <= (-numer) / (-diff)
            // 取整数上界：t <= floor((-numer) / (-diff))
            long long nn = -numer, nd = (long long)(-diff);
            long long bound;
            if (nn >= 0) {
                // 正数除正数，C++ 整数除法自动向零取整，即为向下取整
                bound = nn / nd;
            } else {
                // 负数除正数，需手动向下取整：-((-nn + nd - 1) / nd)
                bound = -((-nn + nd - 1) / nd);
            }
            hi = std::min(hi, bound); // 更新 t 的上界
        }
    }

    // 补充约束：预期价格的总利润必须 >= 0
    // 因为销量为 0 的价格利润恒为 0，若预期价利润 < 0 则不是最优
    // 总利润 = (de + t) * se >= 0，当 se > 0 时要求 t >= -de
    if (se > 0) {
        lo = std::max(lo, (long long)(-de));
    }

    // ========== 第四步：输出结果 ==========

    if (noSol || lo > hi) {
        // 无解：存在无法满足的约束（情况 C），或约束范围为空（下界 > 上界）
        std::cout << "NO SOLUTION" << std::endl;
    } else {
        // 在可行范围 [lo, hi] 中，选取绝对值最小的整数 t
        long long t;
        if (lo <= 0 && hi >= 0) {
            t = 0; // 0 在范围内，无需税收也无需补贴
        } else if (lo > 0) {
            t = lo; // 范围全在正半轴，取最小正值（最少补贴）
        } else {
            t = hi; // 范围全在负半轴，取最大负值（最少收税，即绝对值最小）
        }
        // 输出结果：正数表示补贴，负数表示收税
        std::cout << t << std::endl;
    }

    return 0;
}
