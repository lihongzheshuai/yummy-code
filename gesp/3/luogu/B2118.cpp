#include<iostream>
#include<string>
using namespace std;
int main(){
	string s1, s2;
	cin >> s1 >> s2;
	size_t r1 = s1.find(s2);
	size_t r2 = s2.find(s1);
	if(r1!=string::npos){
		cout << s2 << " is substring of "<< s1;
	}else if(r2!=string::npos){
		cout << s1 << " is substring of " << s2;
	}else{
		cout << "No substring";
	}
	return 0;
}
