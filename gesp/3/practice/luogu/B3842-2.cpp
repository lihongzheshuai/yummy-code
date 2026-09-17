#include<iostream>
using namespace std;
int main(){
	int n,m;
	cin >> n >> m;
	int a[1005];
	int b;
	bool flag = true;
	for(int i = 0;i<n;i++){
		a[i]=0;
	}
	for(int i = 0;i<m;i++){
		cin >> b;
		a[b] = 1;
	}
	for(int i = 0;i<n;i++){
		if(a[i]==0){
			flag = false;
			cout  << i << " ";
		}
	}
	if(flag){
		cout << n;
	}
	return 0;
}
