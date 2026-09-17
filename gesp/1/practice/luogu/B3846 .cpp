#include <cstdio>
using namespace std;
int main() {
    // 定义两个整数变量a和b，用于存储输入的年份范围
    int a, b;
    // 从标准输入读取两个整数，分别存储到a和b中
    scanf("%d%d", &a, &b);
    // 初始化一个整数变量ans，用于存储结果
    int ans = 0;
    // 遍历从a+1到b-1的所有年份
    for (int i = a + 1; i < b; i++) {
        // 判断当前年份是否为闰年
        if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0) {
            // 如果是闰年，则将年份加到ans中
            ans += i;
        }
    }
    // 输出结果
    printf("%d", ans);
    // 返回0，表示程序执行成功
    return 0;
}