#include<iostream>
using namespace std;
int main(){
	long long n;
	cin >> n;
	int ans = 0;
	while(n != 1){
		if(n % 2 == 0){
			n = n / 2;
		}else{
			n = n * 3 + 1;
		}
		ans++;
	}
	cout << ans;
	return 0;
} 
