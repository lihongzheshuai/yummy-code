#include<iostream>
using namespace std;
int main(){
	int n, x;
	cin >> n;
	int a[n+1];
	for(int i = 1;i<=n;i++){
		cin >> a[i];
	}
	cin >> x;
	for(int i = n;i >= 1;i--){
		if(a[i] == x){
			cout << i;
			break;
		}
	}
	return 0;
		
} 
