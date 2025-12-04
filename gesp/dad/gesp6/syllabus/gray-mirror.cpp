#include <algorithm>  // 用于 std::reverse
#include <iostream>
#include <string>
#include <vector>

// 函数：生成 n 位格雷码序列 (使用镜像法)
std::vector<std::string> generateGrayCodeMirror(int n) {
    // 基本情况：0 位格雷码，返回一个包含空字符串的向量
    if (n == 0) {
        return {""};
    }
    // 基本情况：1 位格雷码，直接是 "0", "1"
    if (n == 1) {
        return {"0", "1"};
    }

    // 递归调用：获取 n-1 位格雷码序列
    std::vector<std::string> prevGrayCodes = generateGrayCodeMirror(n - 1);

    std::vector<std::string> currentGrayCodes;

    // 1. 生成前半部分：在每个 n-1 位格雷码前加 '0'
    for (const std::string& code : prevGrayCodes) {
        currentGrayCodes.push_back("0" + code);
    }

    // 2. 生成后半部分：将 n-1 位格雷码序列倒序，然后在每个编码前加 '1'
    // 首先复制并倒序
    std::vector<std::string> reversedPrevGrayCodes = prevGrayCodes;
    std::reverse(reversedPrevGrayCodes.begin(), reversedPrevGrayCodes.end());

    for (const std::string& code : reversedPrevGrayCodes) {
        currentGrayCodes.push_back("1" + code);
    }

    return currentGrayCodes;
}

// 示例用法（可放在 main 函数中测试）
int main() {
    int n_bits = 3;  // 想要生成的格雷码位数
    std::vector<std::string> grayCodes = generateGrayCodeMirror(n_bits);

    std::cout << n_bits << " 位格雷码序列 (镜像法):\n";
    for (const std::string& code : grayCodes) {
        std::cout << code << "\n";
    }
    return 0;
}