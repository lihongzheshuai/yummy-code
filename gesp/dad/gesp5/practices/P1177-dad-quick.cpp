#include <iostream>

// 定义全局大数组，大小 100005，足够存题目指定的 N<=10^5 数据
int ary[100005];

// 快速排序算法 (Quick Sort)，平均时间复杂度 O(N log N)
void quickSort(int l, int r) {
    // 递归边界：当左侧边界大于等于右边界时，该区间段只剩1个或0个元素，自然是有序的
    if (l >= r) {
        return;
    }

    // 用 low 和 high 作为双指针从两端向中间逼近
    int low = l;
    int high = r;

    // 这里采用选取中间元素作为基准元素(pivot/target)的方式
    // 这种做法比单纯选第一个或最后一个更好，能在原始数组基本有序时防止退化到
    // O(N^2)
    int mid = l + (r - l) / 2;
    int target = ary[mid];

    // 将选出来的基准元素和左端点处的元素交换
    // 这样左端点 target(现在的 ary[low]) 就可以看作一个安全的“坑位”供后面填埋
    ary[mid] = ary[low];
    ary[low] = target;

    // 开始进行分割：比 target 小的元素移到其左边，比 target 大的元素移到右边
    while (low < high) {
        // 第一步：从右往左寻找比基准元素 target 小（或等于）的数
        while (low < high && ary[high] > target) {
            high--;
        }
        // 当找到后，把此时的 ary[high] 填入左侧低位留下来的“坑位”ary[low] 中
        if (low < high) {
            ary[low] = ary[high];
            low++;  // 填入后左指针前移一步，同时刚才挪走数据的 high
                    // 成为新“坑位”
        }

        // 第二步：从左往右寻找比基准元素 target 大（或等于）的数
        while (low < high && ary[low] < target) {
            low++;
        }
        // 找到后将其填入右侧高位的“坑位”ary[high]中
        if (low < high) {
            ary[high] = ary[low];
            high--;  // 填入后右指针后移一步，同时刚才的 low 成为了新的“坑位”
        }
    }

    // 当前后指针相遇（low == high），这就是最终基准元素应该在的正确位置
    ary[low] = target;

    // 分治思想：以确定的基准元素所在位置 low
    // 为界，分别递归排序其左半部分和右半部分
    quickSort(l, low - 1);
    quickSort(low + 1, r);
}

int main() {
    int N;
    // 读入元素总个数 N
    std::cin >> N;

    // 依次读入 N 个待排元素到全局数组
    for (int i = 0; i < N; i++) {
        std::cin >> ary[i];
    }

    // 调用最核心的快排函数，范围是从索引 0 开始，到 N-1 结束
    quickSort(0, N - 1);

    // 从小到大依次输出排序后的结果，每个数之后跟随一个空格
    for (int i = 0; i < N; i++) {
        std::cout << ary[i] << " ";
    }
    return 0;
}