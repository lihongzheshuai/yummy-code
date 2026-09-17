/**
 * 题目: 【GESP】C++三级练习 luogu-b2095, 白细胞计数
 * 题号: B2095
 * 归属: GESP3级
 * 博客: https://www.coderli.com/gesp-3-luogu-b2095/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <cmath>
#include <cstdio>
#include <iostream>

using namespace std;
int main() {
    int n; // 输入样本数量
    cin >> n;
    double array[n]; // 存储样本值的数组
    double max_num, min_num, all_sum = 0.0; // 初始化最大值、最小值和总和
    for (int i = 0; i < n; i++) {
        double cur; // 当前样本值
        cin >> cur;
        if (i == 0) {
            max_num = cur; // 初始化最大值
            min_num = cur; // 初始化最小值
        } else {
            max_num = max(max_num, cur); // 更新最大值
            min_num = min(min_num, cur); // 更新最小值
        }
        array[i] = cur; // 将当前样本值存入数组
        all_sum += cur; // 累加总和
    }
    double new_sum = all_sum - max_num - min_num; // 计算去除最大最小值后的总和
    double new_avg = new_sum / (n - 2); // 计算平均值
    double max_diff = 0.0; // 初始化最大差值
    bool have_max = true; // 标记是否已找到最大值
    bool have_min = true; // 标记是否已找到最小值
    for (int i = 0; i < n; i++) {
        if (array[i] == max_num && have_max) {
            have_max = false; // 标记已找到最大值
            continue; // 跳过最大值
        } else if (array[i] == min_num && have_min) {
            have_min = false; // 标记已找到最小值
            continue; // 跳过最小值
        } else {
            max_diff = max(max_diff, abs(array[i] - new_avg)); // 更新最大差值
        }
    }
    printf("%.2f %.2f", new_avg, max_diff); // 输出平均值和最大差值
    return 0;
}
