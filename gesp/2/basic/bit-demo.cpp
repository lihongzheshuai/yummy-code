#include <bitset>
#include <iostream>
using namespace std;
int main() {
    int i = -5;
    int result = i >> 1;
    cout << result << endl;
    result = i >> 2;
    cout << result << endl;
    result = i >> 3;
    cout << result << endl;
    result = i >> 5;
    cout << result << endl;

    int num = 2980;  // 二进制：0101
    if (num & 1) {
        cout << "奇数" << endl;  // 结果是奇数
    } else {
        cout << "偶数" << endl;
    }
    int tmp = 0b1010;  // 二进制：1010
    cout << "结果: " << tmp << endl;
    tmp = tmp | (1 << 2);                        // 设置第 3 位为 1
    cout << "结果: " << bitset<8>(tmp) << endl;  // 输出结果：1110

    int num2 = 0b1110;                                 // 二进制：1110
    num2 = num2 & ~(1 << 2);                           // 清除第 3 位
    cout << "结果: " << std::bitset<8>(num2) << endl;  // 输出结果：00001010

    int num3 = 0b1100;                                     // 二进制：1100
    num3 = num3 ^ 0b0010;                                  // 切换第 2 位
    cout << "切换结果: " << std::bitset<8>(num3) << endl;  // 输出结果：00001110
    int num4 = 0b1110;                                     // 二进制：1100
    num4 = num4 ^ 0b0010;                                  // 切换第 2 位
    cout << "切换结果: " << std::bitset<8>(num4) << endl;  // 输出结果：00001100

    int a = 5;             // 二进制：0101
    int result2 = a << 1;  // 运算过程：0101 << 1 = 1010
    cout << bitset<4>(result2) << endl;
    cout << result2 << endl;

    int b = 5;            // 二进制：0101
    int result3 = b >> 1;  // 运算过程：0101 >> 1 = 0010
    int c = -5;
    int result4 = c >> 1;  // 运算过程：0101 >> 1 = 0010
    cout << bitset<4>(b) << endl;
    cout << bitset<4>(result3) << endl;
    cout << result3 << endl;
    cout << bitset<16>(c) << endl;
    cout << bitset<16>(result4) << endl;
    cout << result4 << endl;       
        int key = 0x5A;  // 加密密钥
    int data = 123;  // 明文数据
    
    // 加密：数据与密钥异或
    int encrypted = data ^ key;
    cout << "加密结果: " << encrypted << endl;
    
    // 解密：加密结果与密钥异或
    int decrypted = encrypted ^ key;
    cout << "解密结果: " << decrypted << endl; 
    return 0;
}