#include<bits/stdc++.h>
using namespace std;
int a[10000005];
int main(){
	int n;
	cin >> n;
	for(int i = 0;i<n;i++){
		cin >> a[i];
	}
	sort(a,a+n);
	int days = 0;
	int last = 0;
	for(int i = 1;i<=n;i++){
		for(int j = last;j<=n;j++){
			if(a[j] >= i){
				days++;
				last = j+1;
				break;
			}
		}
	}
	cout << days;
	return 0;
}
