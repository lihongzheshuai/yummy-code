#include<iostream>
#include<cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int max_serial_count = 1;
    int cur_count = 1;
    for (int i = 0; i < n; i++) {
        if (a[i + 1] == a[i] + 1) {
            cur_count++;
        } else {
            max_serial_count = max(max_serial_count, cur_count);
            cur_count = 1;
        }
    }
    cout << max_serial_count;
    return 0;
}