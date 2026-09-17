#include<iostream>
#include<string>
using namespace std;
int main(){
	string n;
	cin >> n;
	int ans = 0;
	for(int i = 0;i<n.length();i++){
		if(n[i]=='1'){
			ans++;
		}
	}
	cout << ans;
	return 0;
}
