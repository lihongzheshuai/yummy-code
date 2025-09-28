#include <iostream>
#include <cctype>
using namespace std;

int main() {
    char c = 'a';
    if (islower(c)) {
        cout << c << " 是小写字母" << endl;
    } else {
        cout << c << " 不是小写字母" << endl;
    }
    return 0;
}