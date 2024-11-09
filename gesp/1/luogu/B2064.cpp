#include<iostream>
using namespace std;
int main(){
	int n; 
	cin >> n;
	int an = 0;
	for (int i = 0; i < n; i++) {
		cin >> an;
		if (an == 1 || an == 2) {
			cout << 1;
		} else {
			int ans = 0;
			int c = 0;
			int a1 = 1;
			int a2 = 1; 
			for (int j = 3; j <= an; j++ ){
				ans = a2 + a1;
				a1 = a2;
				a2 = ans;
			}
		cout << ans << endl;  
		}

	}
	return 0;
}
