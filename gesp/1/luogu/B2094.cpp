#include<iostream>
using namespace std;
int main(){
	int a, b, c;
	cin >> a >> b >> c;
	if((a >= 60 && b >= 60) && c < 60){
		cout << 1;
	}else if((a < 60 && b >= 60) && c >= 60){
		cout << 1;
	}else if((a >= 60 && b < 60) && c >= 60){
		cout << 1;
	}else {
		cout << 0;
	}
	return 0;
}
