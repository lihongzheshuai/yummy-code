#include <iostream>
#include <cstring>
using namespace std;

// N 表示高精度整数的最大位数（数组长度）
const int N = 1e5 + 5;

// a: 被除数A（高精度整数，低位在下标0）
// b: 除数B（高精度整数，低位在下标0）
// res: 商（高精度整数，低位在下标0）
// tmp: 当前余数（高精度整数，低位在下标0）
int a[N], b[N], res[N];
int tmp[N];

/**
 * 比较两个高精度整数A和B
 * @param A 高精度整数A的数组（低位在下标0）
 * @param la A的长度（有效位数）
 * @param B 高精度整数B的数组
 * @param lb B的长度
 * @return 1: A > B, 0: A == B, -1: A < B
 * 
 * 算法说明：
 * 1. 先比较长度，长度大的数更大。
 * 2. 长度相等时，从高位到低位逐位比较。
 */
int compare(int A[], int la, int B[], int lb) {
    if (la != lb) {
        return la > lb ? 1 : -1;
    }
    for (int i = la - 1; i >= 0; i--) {
        if (A[i] != B[i]) {
            return A[i] > B[i] ? 1 : -1;
        }
    }
    return 0;
}

/**
 * 高精度减法：A -= B，结果保存在A中（假设A >= B）
 * @param A 被减数数组，结果也保存在A中
 * @param la A的长度，按引用传递，可能会减少
 * @param B 减数数组
 * @param lb B的长度
 * 
 * 算法说明：
 * 逐位相减，若当前位不够减则向高位借1（即+10，下一位-1）。
 * 最后去除高位多余的0。
 */
void subtract(int A[], int &la, int B[], int lb) {
    for (int i = 0; i < la; i++) {
        A[i] -= (i < lb ? B[i] : 0); // 若B位数不够则补0
        if (A[i] < 0) {
            A[i] += 10;
            A[i + 1]--;
        }
    }
    // 去除高位多余的0，保证最高位不是0（除非结果为0）
    while (la > 1 && A[la - 1] == 0) {
        la--;
    }
}

/**
 * 向tmp[]右移一位并添加一个新数字
 * @param tmp 当前余数数组（低位在下标0）
 * @param lt 当前余数长度，按引用传递
 * @param digit 要添加的新数字（来自被除数a的高位）
 * 
 * 算法说明：
 * 1. 所有位右移一位，为新数字腾出空间。
 * 2. 新数字放在最低位（下标0）。
 * 3. 更新余数长度lt。
 * 4. 去除高位多余的0。
 */
void push_digit(int tmp[], int &lt, int digit) {
    for (int i = lt; i > 0; i--) {
        tmp[i] = tmp[i - 1];
    }
    tmp[0] = digit;
    lt++;
    // 去除高位多余的0
    while (lt > 1 && tmp[lt - 1] == 0) {
        lt--;
    }
}

/**
 * 高精度加法：C = A + B
 * @param A 数组A（低位在下标0）
 * @param la A的长度
 * @param B 数组B
 * @param lb B的长度
 * @param C 结果数组C
 * @param lc 结果长度，按引用传递
 * 
 * 算法说明：
 * 逐位相加，处理进位，结果存入C。
 */
void add(const int A[], int la, const int B[], int lb, int C[], int &lc) {
    int carry = 0; // 进位
    int len = max(la, lb); // 取较大长度
    for (int i = 0; i < len; ++i) {
        int ai = (i < la) ? A[i] : 0;
        int bi = (i < lb) ? B[i] : 0;
        int val = ai + bi + carry;
        C[i] = val % 10;
        carry = val / 10;
    }
    lc = len;
    if (carry) {
        C[lc++] = carry;
    }
    // 去除高位多余的0
    while (lc > 1 && C[lc - 1] == 0) {
        lc--;
    }
}

/**
 * 试除法，返回当前位的商x和sum = x * B
 * @param tmp 当前余数（低位在下标0）
 * @param lt 当前余数长度
 * @param b 除数（低位在下标0）
 * @param lb 除数长度
 * @param sum 存放x*B
 * @param len_sum sum的长度
 * @return x 当前位的商
 * 
 * 算法说明：
 * 1. 从x=0开始，累加b到local_sum，直到local_sum > tmp。
 * 2. x为能减去的最大次数，sum为x*b。
 * 3. 该过程等价于用加法模拟减法，效率较低但易于理解（二分查找法效率更高，只是暂未学到：）。
 */
int trial_divide(int tmp[], int lt, const int b[], int lb, int sum[], int &len_sum) {
    int x = 0; // 当前位的商
    int local_sum[N] = {0}; // 累加b的结果，表示x*b
    int len_local_sum = 0;  // local_sum的长度

    while (true) {
        int sum2[N] = {0}; // sum2用于存储local_sum + b的结果
        int len_sum2 = 0;  // sum2的实际长度

        // 将local_sum与b相加，结果存入sum2
        add(local_sum, len_local_sum, b, lb, sum2, len_sum2);

        // 如果tmp >= sum2，说明还可能继续加一次b
        if (compare(tmp, lt, sum2, len_sum2) >= 0) {
            // 更新local_sum为sum2，即local_sum += b
            for (int j = 0; j < len_sum2; ++j) {
                local_sum[j] = sum2[j];
            }
            len_local_sum = len_sum2; // 更新local_sum的长度
            x++; // 商加1
        } else {
            // 如果tmp < sum2，不能再加，退出循环
            break;
        }
    }
    // 将local_sum（即x*b的结果）复制到sum数组中
    for (int j = 0; j < len_local_sum; ++j) {
        sum[j] = local_sum[j];
    }
    // 设置sum的实际长度
    len_sum = len_local_sum;
    // 返回当前位的商x
    return x;
}

/**
 * 读取输入并逆序存入数组
 * @param s 输入字符串（高位在前，低位在后）
 * @param arr 存放数字的数组（低位在下标0）
 * @return 数组长度
 * 
 * 算法说明：
 * 1. 从字符串末尾到开头依次存入arr，保证arr[0]为最低位。
 */
int read_and_reverse(const string &s, int arr[]) {
    int len = (int)s.length();
    for (int i = 0; i < len; ++i) {
        arr[len - 1 - i] = s[i] - '0';
    }
    return len;
}

/**
 * 输出高精度整数（高位在前，低位在后）
 * @param arr 数组
 * @param len 长度
 */
void print_bigint(const int arr[], int len) {
    for (int i = 0; i < len; ++i) {
        cout << arr[i];
    }
}

/**
 * 输出高精度整数（逆序，低位在前，高位在后）
 * @param arr 数组
 * @param len 长度
 */
void print_bigint_reverse(const int arr[], int len) {
    for (int i = len - 1; i >= 0; --i) {
        cout << arr[i];
    }
}

int main() {
    // sa, sb为输入的被除数和除数（字符串形式）
    string sa, sb;
    cin >> sa >> sb;

    // la, lb分别为a, b的长度
    int la = read_and_reverse(sa, a);
    int lb = read_and_reverse(sb, b);

    int lt = 0, lr = 0; // lt: 余数长度, lr: 商长度

    // 执行高精度除法
    // 从a的最高位（la-1）到最低位（0）依次处理
    for (int i = la - 1; i >= 0; i--) {
        // 将a[i]加入余数tmp，右移一位
        push_digit(tmp, lt, a[i]);
        int sum[N] = {0}; // 存放x*b
        int len_sum = 0;
        // 试除，得到当前位的商x和x*b
        int x = trial_divide(tmp, lt, b, lb, sum, len_sum);
        res[lr++] = x; // 存入商
        // 用高精度减法更新余数
        subtract(tmp, lt, sum, len_sum);
    }

    // 去除商的前导0（高位的0）
    int p = 0;
    while (p < lr - 1 && res[p] == 0) {
        p++;
    }

    // 输出商（高位在前，低位在后）
    for (int i = p; i < lr; i++) {
        cout << res[i];
    }
    cout << '\n';

    // 输出余数
    cout << "Remainder: ";
    if (lt == 0) {
        cout << 0;
    } else {
        // 余数逆序输出（高位在前）
        print_bigint_reverse(tmp, lt);
    }
    cout << '\n';

    return 0;
}
