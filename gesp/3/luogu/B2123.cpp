#include<iostream>
#include<string>
using namespace std;
int main(){
	string n;
	getline(cin,n);
	int ans = 1;
	for(int i = 0;i<n.length();i++){
		if(n[i+1]==n[i]){
			ans++;
		}else{
			cout << ans << n[i];
			ans=1;
		}
	}
	return 0;
} 
