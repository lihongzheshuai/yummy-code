#include<bits/stdc++.h>
using namespace std;
int c[105],d[105];
int e[105];
int main(){
	string a, b;
	cin >> a >> b;
	int ans_1=0,ans_2=0;
	int c1=1,c2=1;
	for(int i = a.length()-1;i>=0;i--){
		ans_1+=c1*a[i];
		c1*=10;
	}
	for(int i = b.length()-1;i>=0;i--){
		ans_2+=c2*b[i];
		c2*=10;
	}
	if(b.length()>a.length()||ans_2>ans_1){
		swap(a,b);
		cout << "-";
	}
	int l1 = a.length();
	int l2 = b.length();
	for(int i = 0;i<l1;i++){
		c[i] = a[l1 - 1 - i] - '0';
	}
	for(int i = 0;i<l2;i++){
		d[i] = b[l2 - 1 - i] - '0';
	}
	for(int i = 0;i<l1;i++){
		if(c[i]<d[i]){
			c[i]+=10;
			c[i+1] -= 1; 
		}
		e[i] = c[i] - d[i];
	}
	int ans = 1;
	int count = 0;
	for(int i = 0;i<=l1;i++){
		count+=ans*e[i];
		if(count*ans_2==ans_1){
			l1 = i;
		}
	}
	for(int i = l1;i>=0;i--){
		cout << e[i]; 
	}
	return 0;
}
