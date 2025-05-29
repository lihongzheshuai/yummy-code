#include<iostream>
#include<string>
using namespace std;
string a;
int main(){
	cin >> a;
	cout << a.size()<<endl;
	cout << a.length()<<endl;
	cout << a.at(0)<<endl;
	cout << a.substr(0,5)<<endl;
	cout << a.find("sub")<<endl;
	cout << a.rfind("sub")<<endl;
	
}  
