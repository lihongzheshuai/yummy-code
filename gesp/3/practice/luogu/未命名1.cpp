#include<iostream>
#include<string>
using namespace std;
int main(){
	string n;
	getline(cin, n);
	int ans = 0;
	for(int i = 0;i<n.length();i++){
		if(n[i]!=" "){
			ans++;
			continue;
		}else{
			if(ans!=0){
				cout << ans<<" ";
				ans = 0;
			}
		}
	} 
} 
