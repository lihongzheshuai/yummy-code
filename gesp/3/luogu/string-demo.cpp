#include<iostream>
#include<string>
using namespace std;
int main(){
	string n;
	cin >> n;
	string ans = n; 
	for(int i = 0;i<n.length();i++){
		if(ans[i] >= 'A' &&ans[i] <= 'Z'){
			ans[i]+=32;
		}
	} 
	cout << ans << endl;
	cout << n << endl; 
	for(int i = 0;i<n.length();i++){
		if(ans[i] >= 'a' && ans[i] <= 'z'){
			ans[i] -= 32;
		}
	} 
	cout << ans << endl;
	return 0; 
} 
