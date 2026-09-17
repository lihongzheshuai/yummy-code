#include<iostream>
using namespace std;
int main(){
	int a;
	cin >> a;
	long long ans = 1;
	long long sum = 0;
	for(int i = 1;i<= a;i++){
		sum += 1;
		ans *= sum;
		
	}
	cout << ans;
	return 0;
}
