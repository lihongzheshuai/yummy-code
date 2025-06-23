#include<iostream>
#include<string>
using namespace std;
int main() {
	int n;
	cin >> n;
	string z;
	cin >> z;
	for(int i = 0; i<z.length(); i++) {
		int a = z[i];
		int y = a + n;
		if(y>'z') {
			y -= 26;
		} 
		cout << (char)y;
	}
	return 0;
}
