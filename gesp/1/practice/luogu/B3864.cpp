#include <iostream>
using namespace std;
int main() {
    int lucky, first, end;
    cin >> lucky >> first >> end;
    int sum = 0;
    for (int i = first; i <= end; i++) {
        if (i % 10 == lucky || i % lucky == 0) {
            sum += i;
        }
    }
    cout << sum;
    return 0;
}
