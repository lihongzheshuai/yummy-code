#include <iostream>
using namespace std;
int main() {
    int x, y, z, n, m;
    cin >> x >> y >> z >> n >> m;
    int count = 0;
    for (int i = 0; i <= 1000; i++) {
        for (int j = 0; j <= 1000; j++) {
            int chick_num = m - i - j;
            if (chick_num >= 0 && chick_num % z == 0 && i* x + j* y + chick_num / z == n) {
                count++;
            }
        }
    }
    cout << count;
    return 0;
}