#include<iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	int d = n + 1;
	int a[d];
	for(int i =1;i<=n;i++){
		cin >> a[i];
	}
	for(int i = n;i >= 1;i--){
		cout << a[d] << " ";
		d--;
	
	}
	return 0;
}
