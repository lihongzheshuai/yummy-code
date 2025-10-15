#include <iostream>
#include <vector>
using namespace std;

// 合并两个已排好序的子区间 [l, m] 与 [m+1, r]
void merge(vector<int>& a, int l, int m, int r) {
    vector<int> temp;          // 临时数组，存放合并后的有序序列
    int i = l, j = m + 1;      // i 指向前半段首，j 指向后半段首

    // 双指针依次取较小元素放入 temp
    while (i <= m && j <= r) {
        if (a[i] <= a[j]) {
            temp.push_back(a[i++]);
        } else {
            temp.push_back(a[j++]);
        }
    }

    // 处理剩余元素
    while (i <= m) {
        temp.push_back(a[i++]);
    }
    while (j <= r) {
        temp.push_back(a[j++]);
    }

    // 把 temp 中的结果写回原数组对应位置
    for (int k = 0; k < temp.size(); ++k) {
        a[l + k] = temp[k];
    }

}

// 归并排序：对区间 [l, r] 进行排序
// 参数说明：
//   a: 待排序的整型数组（引用传递，排序结果直接写回）
//   l: 当前待排序区间的左端下标（包含）
//   r: 当前待排序区间的右端下标（包含）
void mergeSort(vector<int>& a, int l, int r) {
    if (l >= r) {              // 递归出口：区间长度 ≤ 1 时已有序
        return;
    }
    int m = (l + r) / 2;       // 取中点，将区间一分为二
    mergeSort(a, l, m);        // 递归排序左半部分
    mergeSort(a, m + 1, r);    // 递归排序右半部分
    merge(a, l, m, r);         // 合并两个有序子区间
}

int main() {
    vector<int> arr = {5, 2, 4, 1, 3};
    mergeSort(arr, 0, arr.size() - 1);   // 对整个数组进行归并排序
    for (int x : arr) {
        cout << x << " ";               // 输出排序结果
    }
    return 0;
}