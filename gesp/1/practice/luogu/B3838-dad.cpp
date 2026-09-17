#include <iostream>
using namespace std;
int main() {
    int hour, minute, hour2, minute2;
    cin >> hour >> minute >> hour2 >> minute2;
    cout << (hour2 * 60 + minute2) - (hour * 60 + minute);
    return 0;
}
