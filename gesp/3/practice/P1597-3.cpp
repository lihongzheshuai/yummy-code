/**
 * 题目: 【GESP】C++三级、四级练习 luogu-P1597 语句解析-系列题目4
 * 题号: P1597
 * 归属: GESP3级
 * 解法: 解法 3 / 共 5 种解法
 * 博客: https://www.coderli.com/gesp-4-luogu-p1597-4/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

int main() {
    // ...
    int v_name_idx = 0;  // 变量名位置
    int val_idx = 0;     // 变量值位置
    // 不再需要数组索引

    // 解析所有赋值语句
    while (v_name_idx < str.length() && val_idx < str.length()) {
        // ...
        set_v_value(v_name, v_val); // 不需要传递数组索引
        // ...
    }
    // ...
}
