#include<iostream>
using namespace std;
int main(){
	int n, x;
	cin >> n;
	int a[n];
	for(int i = 0;i<n;i++){
		cin >> a[i];
	}
	cin >> x;
	for(int i = n-1;i >= 0;i--){
		if(a[i] == x){
			cout << i+1;
			break;
		}
	}
	return 0;
		
} 
