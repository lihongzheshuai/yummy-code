#include <iostream>
using namespace std;
<<<<<<< HEAD
int main() {
    int a;
    cin >> a;
    int b, c, d;
    b = a / 100;
    c = a % 100 / 10;
    d = a % 100 % 10;
    int e;
    e = d * 100 + c * 10 + b;
    cout << e;
    return 0;
=======
int main(){
	int a;
	cin >> a; 
    int b, c;
    b = a / 10;
    c = a % 10;
    int d;
    d = c * 10 + b; 
	cout << d;
	return 0;
>>>>>>> feature-code-temp
}
