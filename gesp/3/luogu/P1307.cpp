#include <iostream>
using namespace std;
int main() {
    int a;
    cin >> a;
    int* array = new int[10];
    int index = 0;
    int tmp = 0;
    if (a == 0) {
        cout << 0;
        return 0;
    }
    while (a != 0) {
        int ans = a % 10;
        array[index] = ans;
        a /= 10;
        if (a == 0) {
            break;
        } else {
            index++;
        }
    }
    int y = 1;
    for (int i = index; i >= 0; i--) {
        tmp += array[i] * y;
        y *= 10;
    }
    cout << tmp;
    return 0;
}
