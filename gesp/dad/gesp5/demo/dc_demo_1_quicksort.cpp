#include <iostream>
#include <vector>
using namespace std;

/**
 * 快速排序分区函数
 * 将区间 [l, r] 以 a[r] 为基准划分为两部分：
 * 左侧 ≤ pivot，右侧 ≥ pivot，返回基准最终下标
 * @param a 待分区数组（引用传递）
 * @param l 区间左端下标（包含）
 * @param r 区间右端下标（包含）
 * @return 基准元素最终所在下标
 */
int partition(vector<int>& a, int l, int r) {
    int pivot = a[r];          // 选取最右侧元素作为基准
    int i = l - 1;             // i 指向“已处理且 ≤ pivot”区间的右边界

    for (int j = l; j < r; ++j) {
        if (a[j] <= pivot) {   // 当前元素 ≤ 基准，需归入左侧
            ++i;
            swap(a[i], a[j]);
        }
    }

    // 将基准放到中间正确位置
    swap(a[i + 1], a[r]);
    return i + 1;              // 返回基准下标
}

/**
 * 快速排序（Quick Sort）主函数
 * 对数组区间 [l, r] 进行原地升序排序
 * @param a 待排序的整型数组（引用传递，排序结果直接写回）
 * @param l 当前待排序区间的左端下标（包含）
 * @param r 当前待排序区间的右端下标（包含）
 */
void quickSort(vector<int>& a, int l, int r) {
    if (l >= r) {               // 递归出口：区间长度 ≤ 1 时已有序
        return;
    }
    int p = partition(a, l, r); // 以 a[r] 为基准完成分区，返回基准最终下标
    quickSort(a, l, p - 1);     // 递归排序左半部分（所有元素 ≤ 基准）
    quickSort(a, p + 1, r);   // 递归排序右半部分（所有元素 ≥ 基准）
}

int main() {
    // 初始化待排序数组
    vector<int> arr = {5, 2, 4, 1, 3};
    // 调用快速排序，对数组区间 [0, arr.size()-1] 进行升序排序
    quickSort(arr, 0, arr.size() - 1);
    // 遍历输出排序后的结果
    for (int x : arr) {
        cout << x << " ";
    }
    // 程序正常结束
    return 0;
}