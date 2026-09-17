/**
 * 题目: 【GESP】C++四级真题 luogu-B4068 [GESP202412 四级] Recamán
 * 题号: B4068
 * 归属: GESP4级 (202412认证真题)
 * 博客: https://www.coderli.com/gesp-4-luogu-b4068/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <algorithm>

// 定义数组存储 Recamán 数列
int ary[3005];

/**
 * 判断一个数字是否已经在数列中存在
 * @param num 要判断的数字
 * @param n 当前数列长度
 * @return true 表示数字已存在，false 表示数字不存在
 */
bool is_exist(int num, int n) {
    for (int i = 1; i <= n; i++) {
        if (ary[i] == num) {
            return true;
        }
    }
    return false;
}

int main() {
    // 读入数列长度
    int n;
    std::cin >>n;

    // 初始化第一项为1
    ary[1] = 1;

    // 生成 Recamán 数列
    for (int i = 2; i <= n; i++) {
        // 计算 a[k-1]-k
        int tmp_num = ary[i - 1] - i;

        // 如果 tmp_num 为正且未在数列中出现过，则取 tmp_num
        // 否则取 a[k-1]+k
        if (tmp_num > 0 && !is_exist(tmp_num, i)) {
            ary[i] = tmp_num;
        } else {
            ary[i] = ary[i - 1] + i;
        }
    }

    // 对前n项进行升序排序
    std::sort(ary + 1, ary + n + 1);

    // 输出排序后的结果
    for (int i = 1; i <= n; i++) {
        std::cout << ary[i] << " ";
    }
    return 0;
}
