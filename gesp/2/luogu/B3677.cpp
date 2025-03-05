#include<iostream>
using namespace std;
int main(){
	long long y, t;
	cin >> y >> t;
	if(t==0){
		cout << "NO"<< endl;
		cout << "YES";
		return 0;
	}
	if(y<0&&t%2!=0){
		cout << "YES"<<endl;
	}else{
		cout << "NO"<<endl;
	}
	if(y%2!=0){
		cout << "YES";
	}else{
		cout << "NO";
	}
	return 0; 
} 
