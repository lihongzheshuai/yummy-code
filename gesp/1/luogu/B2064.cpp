#include<iostream>
using namespace std;
int main(){
	int n; 
	cin >> n;
	int* inputs = new int[n];
	int an = 0;
	for (int i = 1; i <= n; i++) {
		cin >> an;
		inputs[i - 1] = an;
	}
	for (int i = 1;i <= n;i++) {
		if (inputs[i - 1] == 1 || inputs[i - 1] == 2) {
			cout << 1 << endl;
		} else {
			int ans = 0;
			int c = 0;
			int a1 = 1;
			int a2 = 1; 
			for (int j = 3; j <= inputs[i - 1]; j++ ){
				ans = a2 + a1;
				a1 = a2;
				a2 = ans;
			}
		cout << ans << endl;  
		}
	}
	return 0;
}
