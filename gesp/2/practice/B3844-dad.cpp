#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int start_char = 'A';
    int end_char = 'A' + 25;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < n; j++) {
            int current_ascii = start_char + j % 26;
            if (current_ascii > end_char) {
                current_ascii -= 26;
            }
            cout << (char)current_ascii;
        }
        cout << endl;
        start_char++;
        if (start_char > end_char) {
            start_char -= 26;
        }
    }
    return 0;
}