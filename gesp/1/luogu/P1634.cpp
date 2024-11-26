#include<iostream>
using namespace std;
int main(){
	long long a, b;
	cin >> a >> b;
	long long ans = 1;
	for(long long i = 0;i < b;i++){
		ans = ans + ans * a;
	} 
	cout << ans;
	return 0;
} 
