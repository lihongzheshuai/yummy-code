#include <cmath>
#include <iostream>
using namespace std;

int main() {
    double x = 100.0;

    cout << "log10(100) = " << log10(x) << endl;  // 输出 2
    cout << "log2(8) = " << log2(8.0) << endl;    // 输出 3
    cout << "ln(e) = " << log(exp(1.0)) << endl;  // 输出 1 (ln e = 1)

    return 0;
}