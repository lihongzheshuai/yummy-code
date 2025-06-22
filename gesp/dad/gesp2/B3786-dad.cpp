#include <iostream>
using namespace std;
int main() {
    int a, b;
    cin >> a >> b;
    int count = 0;
    for (int i = a; i <= b; i++) {
        bool isOdd = true;
        int oddSum = 0;
        int evenSum = 0;
        int curNum = i;
        while (curNum != 0) {
            int digit = curNum % 10;
            if (isOdd) {
                oddSum += digit;
            } else {
                evenSum += digit;
            }
            isOdd = !isOdd;
            curNum /= 10;
        }
        if (oddSum == evenSum) {
            count++;
        }
    }
    cout << count;
    return 0;
}