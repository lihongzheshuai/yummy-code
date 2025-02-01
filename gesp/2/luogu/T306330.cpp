#include<iostream>
using namespace std;
int main(){
	int a[13];
	for(int i = 1;i<=12;i++){
		cin >> a[i];
	}
	for(int i = 12;i>=1;i--){
		if(a[i] >= 90){
			cout << i << " " << a[i];
			break;
		}
	}
	return 0;
} 
