#include <iostream>
using namespace std;
int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        long long x, y;
        cin >> x >> y;
        long long tmp_x = x;
        long long tmp_y = y;
        bool is_f = true;
        while (tmp_x != 0 && tmp_y != 0) {
            if (is_f) {
                if (tmp_x < tmp_y) {
                    tmp_x += 1;
                } else {
                    tmp_x /= 2;
                }
            } else {
                if (tmp_y < tmp_x) {
                    tmp_y += 1;
                } else {
                    tmp_y /= 2;
                }
            }
            is_f = !is_f;
        }
        cout << tmp_x << " " << tmp_y << endl;
    }
    return 0;
}