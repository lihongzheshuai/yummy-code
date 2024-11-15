#include<iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	int a, b, c;
	int ans = 0, bns= 0, cns = 0;
	for(int i = 1;i<=n;i++){
		cin >> a >> b >> c;
		ans += a;
		bns += b;
		cns += c;
	}
	cout << ans << " " << bns << " " << cns << " " << ans + bns + cns;
	return 0;
}
