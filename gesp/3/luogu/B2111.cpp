#include<iostream>
#include<string>
using namespace std;
int main(){
	double n;
	cin >> n;
	string a, b;
	double ans  = 0;
	cin >> a >> b;
	for(int i = 0;i<a.length();i++){
		if(a[i] == b[i]){
			ans++;
		}
	}
	if(ans/a.length()>=n){
		cout << "yes";
	} else{
		cout << "no"; 
	}
	return 0;
}
