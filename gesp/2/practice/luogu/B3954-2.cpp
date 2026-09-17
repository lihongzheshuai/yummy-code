#include<iostream>
using namespace std;
int main(){ 
	int n;
	cin >> n;
	int a;
	long long ans  = 1;
	for(int i = 1;i<=n;i++){
		cin >> a;
		ans*=a;
		if(ans>1000000){
			cout << ">1000000";
			return 0;
		}
	}
	cout << ans;
	return 0;
}
