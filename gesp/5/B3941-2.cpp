#include<bits/stdc++.h>
using namespace std;
int a[15];
long long gcd(long long x, long long y){
	long long l = max(x,y);
	long long s = min(x,y);
	for(int i = 0;;i++){
		long long z = s;
		if(l % s == 0){
			return s;
		}
		s = l % s;
		l = z;
	}
} 
long long lcm(long long x, long long y){
	return x * y / gcd(x,y);
}

int main(){
	int n;
	cin >> n;
	for(int i = 0;i<n;i++){
		cin >> a[i];
	}
	long long b;
	long long y = a[0];
	for(int i = 1;;i++){
		b = lcm(a[i],y); 
		y = b;
		if(i+1 == n){
			break;
		}            
	}
	cout << y;
	return 0;
}
