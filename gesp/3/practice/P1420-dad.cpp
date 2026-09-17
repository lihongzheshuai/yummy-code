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
    for (int i = 0; i < n; i++) {
        int last_num = a[i];
        int cur_serial_count = 1;
        for (int j = i + 1; j < n; j++) {
            if (a[j] == last_num + 1) {
                cur_serial_count++;
                
            } else {
                cur_serial_count = 1;
                
            }
            max_serial_count = max(max_serial_count, cur_serial_count);
            last_num = a[j];
        }
    }
    cout << max_serial_count;
    return 0;
}