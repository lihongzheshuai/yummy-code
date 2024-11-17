#include<iostream>
using namespace std;
int main(){
	int _a;
	cin >> _a;
	while(_a == 1){
		cout << 1 << " ";
	}
	do{
		cout << 1 << " ";
	}
	while(_a == 1);
	cout << _a;
	return 0;
}
