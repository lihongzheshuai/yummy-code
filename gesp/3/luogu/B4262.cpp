#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	string a;
	int b[n];
	for(int i = 0;i<n;i++){
		cin >> a;
		transform(a.begin(),a.end(),a.begin(),::tolower);	
	}
}
