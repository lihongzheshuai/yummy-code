#include <iostream>
#include <vector>
using namespace std;

// 交换两个元素的位置
void swap(vector<int>& nums, int i, int j) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

// 递归生成并输出全排列
void permute(vector<int>& nums, int start) {
    if (start == nums.size()) {
        // 当 start 到达数组末尾时，输出当前排列
        for (int num : nums) {
            cout << num << " ";
        }
        cout << endl;
    } else {
        for (int i = start; i < nums.size(); ++i) {
            // 每次交换当前位置和递归位置上的数字
            swap(nums, start, i);
            // 递归到下一个位置
            permute(nums, start + 1);
            // 回溯，将当前交换的元素恢复
            swap(nums, start, i);
        }
    }
}

int main() {
    vector<int> nums = {1, 2, 3};
    permute(nums, 0);
    return 0;
}
