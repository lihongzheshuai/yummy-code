#include<iostream>
using namespace std;
int main(){
	int a;
	cin >> a;
	int ans = 0;
	int sum = 0;
	for(int i = 1;i <= a;i += 2){
		ans += i;
	}
	for(int i = 0;i <= a;i+=2){
		sum += i;
	}
	cout << sum << " " << ans;
	return 0; 
}
