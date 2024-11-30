#include<iostream>
using namespace std;
int main(){
	int a = 97;
	for(int i = 0;i < 26;i++){
		cout << (char)a << " ";
		a += 1;
	}
	cout << endl;
	int b = 90;
	for(int i = 26;i > 0;i--){
		cout << (char)b << " ";
		b -= 1;
	}
	return 0;
}
