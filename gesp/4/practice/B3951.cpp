/**
 * 题目: 【GESP】C++五级(四级也可)练习（四级排序考点） luogu-B3951 [GESP样题 五级] 小杨的队列
 * 题号: B3951
 * 归属: GESP4级
 * 博客: https://www.coderli.com/gesp-5-luogu-b3951/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <algorithm>

// 存储所有同学的身高，下标即学号
int nums[2005];
// 存储当前已入队同学的身高，按入队顺序排列
int sort_nums[2005];

/**
 * 计算将新入队的同学（位于 sort_nums[target_idx]）通过最少交换插入到已排序片段所需次数
 * 策略：从后往前找到第一个比当前同学高的“不同”身高，每遇到一个就交换并继续前移，直到无法再前移
 * @param target_idx 新入队同学在 sort_nums 中的下标
 * @return 最少交换次数
 */
int get_counts(int target_idx) {
    int count = 0;
    if (target_idx == 0) {
        return 0; // 第一个同学无需交换
    }
    // 从紧邻的前一个位置开始向前扫描
    for (int i = target_idx - 1; i >= 0; i--) {
        // 若当前同学身高更小，且与前一个身高不同（避免重复计数相同身高）
        if (sort_nums[target_idx] < sort_nums[i] && (i == 0 || sort_nums[i] != sort_nums[i - 1])) {
            count++;                     // 需要一次交换
            std::swap(sort_nums[target_idx], sort_nums[i]); // 交换到正确相对位置
            target_idx = i;              // 继续把“新位置”当作 target 前移
        }
    }
    return count;
}

int main() {
    int N;
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::cin >> nums[i]; // 读入每位同学的身高
    }
    int M;
    std::cin >> M;
    for (int i = 0; i < M; i++) {
        int s_num;
        std::cin >> s_num;          // 读入当前被点名的学号
        sort_nums[i] = nums[s_num]; // 把该同学身高加入队伍末尾
        int count = get_counts(i);  // 计算本次最少交换次数
        std::cout << count << std::endl;
    }
    return 0;
}
