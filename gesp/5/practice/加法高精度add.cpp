#include<bits/stdc++.h>
using namespace std;
string a,b;
int d[105],e[105];
int f[105];
int main(){
	cin >> a >> b;
	int c1 = (int)a.length();
	int c2 = (int)b.length();
	int c = max(c1,c2);
	for(int i = 0;i<c1;i++){
		d[i] = a[c1-1-i]-'0';
	}
	for(int i = 0;i<c2;i++){
		e[i] = b[c2-1-i]-'0';
	}
	int carry = 0;
	for(int i = 0;i<c;i++){
		int num = d[i]+e[i]+carry;
		f[i] = num % 10;
		carry = num / 10;
	}
	if(carry){
		f[c] = carry;
		c++;
	}
	for(int i = c-1;i>=0;i--){
		cout << f[i];
	}
	return 0;
} 
