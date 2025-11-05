#include<bits/stdc++.h>
using namespace std;
int main(){
	int a, b;
	cin >> a >> b;
	int g = gcd(a, b);
	int l = lcm(a, b);
	cout << g << " " << l;
} 
