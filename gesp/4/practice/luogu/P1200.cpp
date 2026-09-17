#include<iostream>
#include<string>
using namespace std;
int main(){
	string a;
	string b;
	cin >> a >> b;
	for(int i = 0;i<a.length();i++){
		a_count *= (a[i]-64);
	}
	for(int i = 0;i<b.length();i++){
		b_count *= (b[i]-64);
	}
	if(a_count%47 == b_count%47){
		cout << "GO";
	}else{
		cout << "STAY";
	}
	return 0;
}
