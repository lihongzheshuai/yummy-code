#include <algorithm>
#include <iostream>
#include <vector>

// 高精度乘法：计算两个大整数的乘积
std::string big_multi(std::string a, std::string b) {
    int a_l = a.size();
    int b_l = b.size();
    // 储存按位相乘的结果，最大长度不会超过两个数字长度之和
    std::vector<int> res(a_l + b_l, 0);
    // 模拟竖式乘法，不考虑进位直接相乘累加
    for (int i = a_l - 1; i >= 0; i--) {
        for (int j = b_l - 1; j >= 0; j--) {
            res[i + j] += (a[i] - '0') * (b[j] - '0');
        }
    }
    std::string ans;
    // 从低位到高位处理进位
    for (int i = a_l + b_l - 2; i >= 1; i--) {
        if (res[i] >= 10) {
            res[i - 1] += res[i] / 10;  // 向前进位
            res[i] %= 10;               // 保留个位数字
        }
        ans = std::to_string(res[i]) + ans;  // 拼接到结果前
    }
    // 处理最高位（如果有）
    if (res[0] > 0) {
        ans = std::to_string(res[0]) + ans;
    }
    return ans;
}

// 高精度加法：计算两个大整数的和
std::string big_sum(std::string a, std::string b) {
    std::string res = "";
    int n = a.size(), m = b.size();
    int len = std::max(n, m);
    // 反转字符串，方便从低位（个位）开始相加
    std::reverse(a.begin(), a.end());
    std::reverse(b.begin(), b.end());
    int carry = 0;  // 进位标志
    for (int i = 0; i < len; i++) {
        int cura = (i < n) ? a[i] - '0' : 0;  // 若该位没有数字，则用0补齐
        int curb = (i < m) ? b[i] - '0' : 0;
        int tmp = cura + curb + carry;    // 计算当前位的和加上进位
        res += std::to_string(tmp % 10);  // 当前位只保留个位
        carry = tmp / 10;                 // 计算新的进位
    }
    // 如果最后还有进位，需要补上
    if (carry > 0) {
        res += std::to_string(carry);
    }
    // 因是从低位往高位加的，最后需将结果字符串反转过来
    std::reverse(res.begin(), res.end());
    return res;
}

int main() {
    int n;
    std::cin >> n;  // 读取输入 n

    // multiplier 用于储存当前项的阶乘（初始为 1! = 1）
    std::string multiplier = "1";
    // ans 用于储存阶乘的累加和（初始为 1! 的和）
    std::string ans = "1";

    // 从 2 开始，一直到 n，累加每一项的阶乘
    for (int i = 2; i <= n; i++) {
        // 计算当前项 i!，即 i! = (i-1)! * i
        multiplier = big_multi(multiplier, std::to_string(i));
        // 将 i! 累加到最终结果 ans 中
        ans = big_sum(ans, multiplier);
    }

    // 输出总和 S = 1! + 2! + 3! + ... + n!
    std::cout << ans << std::endl;
    return 0;
}
