/**
 * 题目: 【NOIP】2000真题解析 luogu-P1022 计算器的改良（适合GESP四、五级以上练习）
 * 题号: P1022
 * 归属: GESP5级
 * 博客: https://www.coderli.com/noip-2000-luogu-p1022/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <cstdio>
#include <cstring>

int main() {
    char eq[1000];
    scanf("%s", eq);
    int len = strlen(eq);

    // 找到未知数字母
    char var = 0;
    for (int i = 0; i < len; i++) {
        if (eq[i] >= 'a' && eq[i] <= 'z') {
            var = eq[i];
            break;
        }
    }

    double coeff = 0;    // 未知数系数之和（归到左侧）
    double constant = 0; // 常数之和（归到右侧）
    int side = 1;        // 等号左侧 +1，右侧 -1
    int sign = 1;        // 当前项的正负号
    int num = 0;         // 当前积累的数值
    bool hasNum = false; // 是否已读取到数字

    for (int i = 0; i < len; i++) {
        char c = eq[i];
        if (c >= '0' && c <= '9') {
            // 累积数字
            num = num * 10 + (c - '0');
            hasNum = true;
        } else if (c == var) {
            // 遇到未知数字母，处理系数项
            if (!hasNum) {
                num = 1; // 省略系数时，系数为 1
            }
            coeff += side * sign * num;
            // 重置
            num = 0;
            hasNum = false;
            sign = 1;
        } else if (c == '+' || c == '-') {
            // 遇到运算符，先处理前一项（如果是常数项）
            if (hasNum) {
                // 前一项是纯数字（常数项），移到右边（取反）
                constant -= side * sign * num;
            }
            // 重置并更新符号
            num = 0;
            hasNum = false;
            sign = (c == '+') ? 1 : -1;
        } else if (c == '=') {
            // 处理等号前的最后一项
            if (hasNum) {
                constant -= side * sign * num;
            }
            // 切换到等号右侧
            side = -1;
            num = 0;
            hasNum = false;
            sign = 1;
        }
    }

    // 处理方程末尾的最后一项
    if (hasNum) {
        constant -= side * sign * num;
    }

    // 计算结果，处理负零问题
    double result = constant / coeff;
    if (result == 0.0) {
        result = 0.0; // 避免输出 -0.000
    }

    // 输出结果，精确到小数点后三位
    printf("%c=%.3f\n", var, result);

    return 0;
}
