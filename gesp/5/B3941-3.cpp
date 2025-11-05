#include<bits/stdc++.h>
using namespace std;
long long gcd(long long a,long long b){
	if(a%b==0){
		return b;
	}
	return gcd(b,a%b);
}
long long lcm(long long a, long long b){
	long long x = max(a,b);
	long long y = min(a,b);
	return x * y / gcd(x,y);
}
int a[12];
int main(){
	int n;
	cin >> n;
	for(int i = 0;i<n;i++){
		cin >> a[i]; 
	} 
	long long z = a[0];
	for(int i = 1;i<n;i++){
		z = lcm(z,a[i]);
	}
	cout << z;
	return 0;
} 
