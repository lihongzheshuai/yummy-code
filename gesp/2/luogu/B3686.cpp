#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int x, y, z;
	cin >> x >> y >> z;
	cout << min(x,y + z) << endl;
	cout << min(y,x+z) << endl;
	cout << min(z,x+y) << endl;
	return 0;
}
