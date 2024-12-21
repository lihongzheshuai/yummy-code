#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int even = 0;
    int odd = 0;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        if (num % 2 == 0) {
            even++;
        } else {
            odd++;
        }
    }
    cout << odd << " " << even;
    return 0;
}