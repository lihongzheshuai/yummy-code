#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int start_char = 'A';
    int idx = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            int current_ascii = start_char + idx % 26;
            cout << (char)current_ascii;
            idx++;
        }
        cout << endl;
    }
    return 0;
}