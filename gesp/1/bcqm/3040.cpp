#include<iostream>
using namespace std;
int main(){
	int n, k;
	cin >> n >> k;
<<<<<<< HEAD
	for(int i = n; i >= 1;i--){
		if (i % k == 0) {
			cout << i;
			break;
		}
	}
=======
	int c, ans = 0;
	if(c < n && k % c == 0){
		ans += 1;
	}
	cout << ans;
>>>>>>> feature-code-temp
	return 0;
}
