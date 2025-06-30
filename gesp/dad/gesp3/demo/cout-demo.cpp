#include <iostream>
#include <iomanip>   // oct, hex, dec, showbase, uppercase
#include <bitset>    // bitset 用于二进制输出

using namespace std;

int main() {
    int value = 255;

    // 十进制（默认）
    cout << "十进制: " << value << endl;

    // 八进制输出
    cout << oct;
    cout << "八进制（无前缀）: " << value << endl;
    cout << showbase << "八进制（带前缀）: " << value << endl;

    // 十六进制输出
    cout << hex;
    cout << "十六进制（小写）: " << value << endl;
    cout << uppercase << "十六进制（大写）: " << value << endl;
    cout << showbase << "十六进制（大写带前缀）: " << value << endl;

    // 恢复十进制
    cout << dec << nouppercase << noshowbase;
    cout << "恢复十进制: " << value << endl;

    // 二进制输出
    cout << "二进制（8位）: " << bitset<8>(value) << endl;
    cout << "二进制（16位）: " << bitset<16>(value) << endl;

    int x = 255;

    cout << hex << showbase << uppercase;
    cout << "十六进制格式输出: " << x << endl;  // 输出: 0XFF

    // 下一行也会被格式影响（仍是 hex、showbase、uppercase）
    cout << "再次输出十六进制: " << x << endl;  // 输出: 0XFF

    // ✅ 显式恢复为默认设置
    cout << dec << noshowbase << nouppercase;
    cout << "恢复十进制输出: " << x << endl;   // 输出: 255

    // setw 只对下一个输出有效
    cout << setfill('0') << setw(5) << x << " ";
    cout << x << endl;  // 第二个 x 没有被 setw(5) 影响

    return 0;
}