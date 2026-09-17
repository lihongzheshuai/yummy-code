#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int n;
	cin >> n;
	int a;
	int m=0,u=10000;
	for(int i = 1;i<=n;i++){
		cin >> a;
		m=max(a,m);
		u=min(a,u);
	}
	cout << m - u;
	return 0;
} 
