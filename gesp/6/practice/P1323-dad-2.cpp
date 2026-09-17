#include <iostream>
#include <queue>
#include <vector>

int main() {
    int k, m;
    std::cin >> k >> m;
    std::vector<int> nums;
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    pq.push(1);
    while (nums.size() < k) {
        int x = pq.top();
        pq.pop();
        if (!nums.empty() && x == nums.back()) {
            continue;
        }
        nums.push_back(x);
        pq.push(2 * x + 1);
        pq.push(4 * x + 5);
    }
    std::string s = "";
    for (int x : nums) {
        s += std::to_string(x);
    }
    std::cout << s << std::endl;

    std::string ans = "";

    for (char c : s) {
        while (m > 0 && !ans.empty() && ans.back() < c) {
            ans.pop_back();
            m--;
        }
        ans.push_back(c);
    }

    while (m > 0) {
        ans.pop_back();
        m--;
    }

    std::cout << ans << std::endl;

    return 0;
}