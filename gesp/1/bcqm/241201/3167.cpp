#include<iostream>
using namespace std;
int main(){
	int a;
	cin >> a;
	int n, q, e;
	int ans=0, bns=0, cns=0;
	for(int i = 1;i <= a;i++){
		cin >> n >> q >> e;
		ans += n;
		bns += q;
		cns += e;
	}
	cout << ans << " " << bns << " " << cns << " " << ans + bns + cns;
	return 0; 
}
