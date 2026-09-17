#include<bits/stdc++.h>
using namespace std;
int a[30005];
int b[30005];
int main(){
	int n;
	cin >> n;
	a[1] = 1;
	b[1] = 1;
	int last = a[1];
	for(int i = 2;i<=n;i++){
		if(last - i > 0&&b[last - i] == 0){
			a[i] = last - i;
			b[a[i]] = 1;
			last = a[i];
		}else{
			a[i] = last + i;
			b[a[i]] = 1;
			last = a[i];
		}
	}
	sort(a+1,a+n+1);
	for(int i = 1;i<=n;i++){
		cout << a[i] << " ";
	}
	return 0;
} 
