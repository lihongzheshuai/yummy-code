#include<iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	int ans = 0;
	int m = n-1;
	while(m!=0){
		ans+=m*2;
		m--;
	}
	ans += (n-1);
	cout << ans;
	return 0;
}
