#include<iostream>
using namespace std;
int main(){
	int first, second, third, money;
	cin >> first >> second >> third >> money;
	if(money >= first * 2 + second * 5 + third * 3){
		cout << "Yes" << endl;
		cout << money - (first * 2 + second * 5 + third * 3);
	}else{
		cout << "No" << endl;
		cout << (first * 2 + second * 5 + third * 3) - money;
	}
	return 0;
}
