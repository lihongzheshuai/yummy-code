#include <cmath>
#include <iostream>
using namespace std;
int main() {
    int L;
    cin >> L;
    int count = 0;
    int sum = 0;
    int cur_num = 2;
    while (true) {
        bool is_prime = true;
        if (cur_num > 3) {
            for (int i = 2; i <= sqrt(cur_num); i++) {
                if (cur_num % i == 0) {
                    is_prime = false;
                    break;
                }
            }
        }
        if (is_prime) {
            sum += cur_num;
            if (sum <= L) {
                cout << cur_num << endl;
                count++;
            } else {
                cout << count;
                break;
            }
        }

        cur_num++;
    }
    return 0;
}