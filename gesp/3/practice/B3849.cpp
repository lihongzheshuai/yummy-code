/**
 * 题目: 【GESP】C++三级模拟题 luogu-B3849 [GESP样题 三级] 进制转换
 * 题号: B3849
 * 归属: GESP3级
 * 博客: https://www.coderli.com/gesp-3-luogu-b3849/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <string>

int main() {
    // 声明变量存储十进制数N和目标进制R
    int N, R;
    std::cin >> N >> R;

    // 用字符串存储结果
    std::string result = "";

    do {
        // 获取当前位的值
        int cur = N % R;
        // 更新N为商
        N /= R;

        char c;
        // 如果当前位大于9，需要用字母A-Z表示
        if (cur > 9) {
            c = char(cur - 10 + (int)'A');
        } else {
            // 否则用数字0-9表示
            c = char(cur + '0');
        }
        // 将当前位添加到结果字符串的开头
        result = c + result;
    } while (N != 0);  // 当N不为0时继续循环

    // 输出结果
    std::cout << result;
    return 0;
}
