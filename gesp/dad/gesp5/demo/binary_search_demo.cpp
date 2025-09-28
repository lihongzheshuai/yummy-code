#include <iostream>
#include <vector>
using namespace std;

// 二分查找函数
int binary_search(vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2; // 避免溢出
        if (arr[mid] == target) {
            return mid; // 找到目标
        } else if (arr[mid] < target) {
            left = mid + 1; // 目标在右边
        } else {
            right = mid - 1; // 目标在左边
        }
    }
    return -1; // 未找到
}

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11};
    int target;
    cout << "请输入要查找的数字: ";
    cin >> target;

    int result = binary_search(arr, target);
    if (result != -1) {
        cout << "目标 " << target << " 出现在下标 " << result << endl;
    } else {
        cout << "目标 " << target << " 不存在于数组中" << endl;
    }
    return 0;
}