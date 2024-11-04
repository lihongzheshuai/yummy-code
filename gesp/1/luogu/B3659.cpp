#include<iostream>
using namespace std;
int main(){
	int n, k;
	cin >> n >> k;
	int ans = 0;
	int b;
	for(int i = 1;i <= n;i++){
		cin >> b;
		if(b == k){
			ans += 1;
		}else{
			ans += 0;
		}
	}
	cout << ans;
	return 0;
}
