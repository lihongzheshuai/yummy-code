#include <iostream>
using namespace std;
int main() {
    int x, y;
    cin >> x >> y;
    int chicken, rabbit;
    chicken = (x  * 4 - y) / 2;
    rabbit = x - chicken;
    cout<< chicken << " " << rabbit;
    return 0;
}
