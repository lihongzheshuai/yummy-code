#include<iostream>
using namespace std;
int main(){
	int n, m;
	cin >> n >> m;
	int c[n] = {0};
	int b[n] = {0};
	int a[m];
	int ans  =0;
	bool flag = true;
	for(int i = 0;i<m;i++){
		cin >> a[i];
	} 
	for(int i = 0;i<m;i++){
		b[a[i]] = 1; 
	}
	for(int i = 0;i<n;i++){
		if(b[i] == 0){
			c[i] = 0;
			flag = false;
			continue;
		}else{
			c[i] = 1;
		}
	}
	for(int i = 0;i<n;i++){
		if(c[i]==0){
			cout << i << " ";	
		}
	}
	if(flag){
		cout << n;
	}
	return 0;
}
