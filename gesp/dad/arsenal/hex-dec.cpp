#include <iostream>
#include <string>
using namespace std;

int hexToDec(const string& s) {
    int result = 0;
    for (char c : s) {
        int value;
        if (c >= '0' && c <= '9') {
            value = c - '0';
        } else if (c >= 'A' && c <= 'F') {
            value = c - 'A' + 10;
        } else if (c >= 'a' && c <= 'f') {
            value = c - 'a' + 10;
        } else {
            continue; // 跳过不合法字符
        }
        result = result * 16 + value;
    }
    return result;
}

int main() {
    string s = "FE";
    cout << hexToDec(s) << endl;  // 输出 254
    return 0;
}