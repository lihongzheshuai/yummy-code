#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// 优先队列保证每次取出最小的元素
priority_queue<int, vector<int>, greater<int>> pq;
// 存储生成的最小的k个数
vector<int> nums;

int main() {
    int k, m;
    cin >> k >> m;

    // 1. 构造数据：生成集合中最小的k个元素
    // 初始元素1入队
    pq.push(1);

    // 循环取出最小元素并生成新元素，直到收集满k个
    // 注意：虽然题目生成规则下不易产生重复，但为了严谨通常可以判重
    // 这里因为是严格递增取出的，可以简单判断是否等于上一个取出的数
    while (nums.size() < k) {
        int x = pq.top();
        pq.pop();

        // 如果和上一个存入的数相同，则是重复元素，跳过
        if (!nums.empty() && nums.back() == x) {
            continue;
        }

        nums.push_back(x);

        // 生成新元素加入队列
        // 题目保证k<=30000，为了防止int溢出，可以稍微留意一下，但此处2*P+1在k=30000时也不会溢出int
        pq.push(2 * x + 1);
        pq.push(4 * x + 5);
    }

    // 将这k个数按顺序拼接成一个大整数（字符串形式）
    string s = "";
    for (int x : nums) {
        s += to_string(x);
    }

    // 输出删除前的数字
    cout << s << endl;

    // 2. 删数逻辑：删除m个数字，使得剩下的数最大
    // 贪心策略：若高位数字小于后一位数字，则删除该高位数字
    // 使用单调递减栈的思想：
    // 遍历字符串中的每个字符 c
    // 如果 ans 的最后一位数字 < c，并且还有删除次数(m>0)，说明删除 ans
    // 末尾的数字能让更大的 c 占据高位，更优
    string ans = "";
    for (char c : s) {
        // 当还有删除机会，且栈非空，且栈顶元素小于当前元素 c 时
        while (m > 0 && !ans.empty() && ans.back() < c) {
            ans.pop_back();  // 删除栈顶较小的数字
            m--;             // 消耗一次删除机会
        }
        ans.push_back(c);
    }

    // 如果遍历完后 m 仍大于 0，说明已经是非递减序列（或者所有逆序对都删完了），
    // 此时应该从末尾删除剩余的 m 个数字（因为末尾是最小的或者对高位影响最小的）
    while (m > 0 && !ans.empty()) {
        ans.pop_back();
        m--;
    }

    // 输出删除后的最大数
    cout << ans << endl;

    return 0;
}