#include<iostream>
#include<cmath>
using namespace std;
int main(){
	long long n;
	cin >> n;
	long long a;
	long long ans = 0;
	for(int i = 1;i<=n;i++){
		long long y = 0;
		cin >> a;
		long long g = a;
		while(g!=0){
			y+=g%10;
			g/=10;
		}
		ans = max(ans,y);
	}
	cout << ans;
	return 0;
}
