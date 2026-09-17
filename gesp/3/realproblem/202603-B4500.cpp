/**
 * 题目: 【GESP】C++三级真题 luogu-B4500, [GESP202603 三级] 凯撒密码
 * 题号: B4500
 * 归属: GESP3级 (202603认证真题)
 * 博客: https://www.coderli.com/gesp-3-luogu-b4500/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <string>

int main() {
    // 定义三个字符串，分别存放已知明文、已知密文、待破解的密文
    std::string plaintext1, ciphertext1, ciphertext2;
    std::cin >> plaintext1 >> ciphertext1 >> ciphertext2;

    // 1. 求出加密用的标准偏移量 offset
    // 我们只需要用第一个已知密文字符减去第一个已知明文字符
    // 为了防止出现负数偏移或者越界，这里加上 26 再对 26 取余，确保它是一个标准的正向偏移。
    int offset = (ciphertext1[0] - plaintext1[0] + 26) % 26;

    // 初始化一个用来装配最终解密结果的字符串
    std::string result = "";

    // 2. 遍历待破解字符中的每一个密文字符
    for (int i = 0; i < ciphertext2.length(); i++) {
        char ch = ciphertext2[i];

        // 先算出该字符距离字母 'A' 有几个位置（相对序号 0-25）
        // 减去偏移量 offset，如果不够减出现了负数就先加上 26，再对 26 取模以实现轮回闭环。
        int decryptedIndex = (ch - 'A' - offset + 26) % 26;

        // 再把算好的新相对序号变回去，加上 'A' 的基数，变回大写字母
        char decryptedChar = 'A' + decryptedIndex;

        // 拼接到最终结果字符串末尾
        result += decryptedChar;
    }

    // 3. 打印最终解密好的明文
    std::cout << result << std::endl;

    return 0;
}
