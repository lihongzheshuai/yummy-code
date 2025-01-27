#include <iostream>
using namespace std;
int main() {
    int k;
    cin >> k;
    int count = 0;
    int days = 1;
    int temp_count = 0;
    for (int i = 1; i <= k; ) {
        for (int j = 1; j <= days && i <= k; j++) {
            count += days;
            i++;
        }
        days++;
    }
    cout << count;
    return 0;
}