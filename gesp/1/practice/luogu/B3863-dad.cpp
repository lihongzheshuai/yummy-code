#include <iostream>
using namespace std;
int main() {
    int first, second, third, money;
    cin >> first >> second >> third >> money;
    int total_cost = first * 2 + second * 5 + third * 3;
    if (money >= total_cost) {
        cout << "Yes" << endl;
        cout << money - total_cost;
    } else {
        cout << "No" << endl;
        cout << total_cost - money;
    }
    return 0;
}
