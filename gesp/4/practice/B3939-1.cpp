/**
 * 题目: 【GESP】C++四级练习 luogu-B3939 [GESP样题 四级] 绝对素数
 * 题号: B3939
 * 归属: GESP4级
 * 解法: 解法 1 / 共 2 种解法
 * 博客: https://www.coderli.com/gesp-4-luogu-b3939/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

int main() {
       int A, B;
       cin >> A >> B;
       // 遍历区间[A,B]
       for (int i = A; i <= B; i++) {
           if (is_abs_prime_number(i)) {
               cout << i << "\n";
           }
       }
       return 0;
   }
