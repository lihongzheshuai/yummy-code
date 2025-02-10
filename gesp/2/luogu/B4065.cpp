#include<iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	long long a;
	long long max=0;
	for(int i = 1;i<=n;i++){
		cin >> a;
		int ans = 0;
		while(a!=0){
			int j = a%10;
			ans+=j;
			a/=10;
		}
		if(ans>max){
			max=ans;
		}
	}
	cout << max;
	return 0;
}
