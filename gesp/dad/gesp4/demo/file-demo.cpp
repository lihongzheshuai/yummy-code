#include <iostream>
#include <fstream>
using namespace std;

int main() {
    freopen("demo.in", "r", stdin);    // 重定向 cin 到 demo.in
    // freopen("demo.out", "w", stdout);  // 重定向 cout 到 demo.out

    int x,y,z;
    cin >> x >> y >> z;   // 实际上是从 demo.in 读取
    string str;
    cin.ignore();
    getline(cin,str);
    cout << x + y + z << endl;  // 实际上是写入 demo.out
    cout << str;

    return 0;
}