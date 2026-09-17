#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    // --- 1. 数组示例 ---
    int a[] = {10, 20, 30, 40};
    // 查找 >= 30 的第一个元素
    int* p = lower_bound(a, a + 4, 30);  // 返回指针

    cout << "数组找到的值: " << *p << endl;  // 解引用取值 -> 30
    cout << "数组下标: " << p - a << endl;   // 指针减法取下标 -> 2

    // --- 2. Vector 示例 ---
    vector<int> v = {10, 20, 30, 40};
    // 查找 >= 30 的第一个元素
    auto it = lower_bound(v.begin(), v.end(), 30);  // 返回迭代器

    cout << "Vector找到的值: " << *it << endl;         // 解引用取值 -> 30
    cout << "Vector下标: " << it - v.begin() << endl;  // 迭代器减法取下标 -> 2

    return 0;
}