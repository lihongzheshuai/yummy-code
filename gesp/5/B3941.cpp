#include<bits/stdc++.h>
using namespace std;
int a[15];
bool pan(int b,int c){
	bool flag = true;
	for(int i = 0;i<c;i++){
		if(b % a[i] != 0){
			flag = false;
		}
	}
	if(flag){
		return true;
	}
	return false;
}
int main(){
	int n;
	cin >> n;
	for(int i = 0;i<n;i++){
		cin >> a[i]; 
	}
	sort(a,a+n);
	int b = a[n-1];
	int c = n; 
	while(true){
		if(pan(b,c)){
			cout << b;
			break;
		}else{
			b+=a[n-1];
		}
	}
	return 0;
} 
