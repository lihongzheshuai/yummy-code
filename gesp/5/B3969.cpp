#include<bits/stdc++.h>
using namespace std;
int a[10000005];
bool pan(int x) {
	if(x == 1) {
		return false;
	}
	if(x == 2) {
		return true;
	}
	for(int i = 2;i <= sqrt(x);i++){
		if(x%i==0){
			return false;
		}
	}
	return true;
}
int main() {
//	freopen("B3969.in","r",stdin);
//	freopen("B3969.out","w",stdout);
	int n,b;
	cin >> n>>b;
	int count = 1;
	for(int i = 1;i<=b;i++){
		if(pan(i)){
			a[i] = 1;
		}
	}
	for(int i = 1;i<=b;i++){
		if(a[i]==1){
			for(int j = i;j<=n;j+=i){
				a[j] = 1;
			}
		}
	}
	for(int i = b+1;i<=n;i++){
		if(pan(i)){
			for(int j = i;j<=n;j+=i){
				a[j] = 0;
			}
		}
	}
	for(int i = 1;i<=n;i++){
		if(a[i]==1){
			count++;
		}
	}
	cout << count;
	return 0;
}
