#include<iostream>
using namespace std;
int main(){
	int a, b;
	char c;
	cin >> a >> b >> c;
	if((b == 0 && c == '/')){
		cout << "Divided by zero!";
	}
	if(c == '+' && b != 0){
		cout << a + b;
	}
	if(c == '-' && b != 0){
		cout << a - b;
	}
	if(c == '*' && b != 0){
		cout << a * b;
	}
	if(c == '/' && b != 0){
		cout << a / b;
	}
	if(((c != '+' && c != '-') && c != '*') && c != '/'){
		cout << "Invalid operator!";
	}
	return 0;
}
