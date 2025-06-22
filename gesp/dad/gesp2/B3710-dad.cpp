#include<iostream>
using namespace std;
int main() {
    double S;
    cin >> S;
    int target = S * 100000000;
    int count = 0;
    for (int i = 0; i <= 100; i++) {
        for (int j = 0; j <= 100; j++) {
            for (int k = 0; k <= 100; k++) {
                for (int l = 0; l <= 100;l++) {
                    if ((100 - i) * (100 - j) * (100 -k) * (100 - l)== target) {
                        count++;
                    }
                }
            }
        }
    }
    cout << count;
    return 0;
}