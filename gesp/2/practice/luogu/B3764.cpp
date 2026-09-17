#include<iostream>
using namespace std;
int main(){
	int t, n;
	cin >> t;
	for(int i = 1;i<=t;i++){
		cin >> n;
		unsigned long long ans = 1;
		if (n % 2 != 0) {
			for (int j = 2; j <= n-1; j+= 2) {
				ans *= j;
			}
		} else {
			for(int f = 1;f<=n-1;f+=2){
				ans *= f;
			}
		}
		cout << ans * 2 << endl;
	}
	return 0;  
}
