#include <iostream>
using namespace std;
int main() {
    int k;
    cin >> k;
    int count = 0;
    int days = 1;
    int now_coins = 1;
    for (int i = 1; i <= k; i++) {
        count += now_coins;
        days--;
        if (days == 0) {
            now_coins++;
            days = now_coins;
        }
    }
    cout << count;
    return 0;
}