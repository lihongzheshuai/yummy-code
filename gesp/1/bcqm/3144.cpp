#include<iostream>
using namespace std;
int main(){
	int a = 97;
	for(int i=1;i<=26;i++){
		cout << (char)a;
		a += 1;
	}
	return 0;
}
