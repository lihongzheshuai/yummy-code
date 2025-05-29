#include<iostream>
#include<string>
using namespace std;
int main(){
	string n;
	getline(cin,n);
	string ans;
	for(int i =0;i<n.length();i++){
		if(n[i]==' '){
			cout << ans<<endl;
			ans="";
		} else{
			ans=n[i]+ ans;
		}
	}
 	cout << ans << endl; 
	return 0;
}
