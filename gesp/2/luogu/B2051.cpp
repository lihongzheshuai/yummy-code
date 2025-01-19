#include<iostream>
using namespace std;
int main(){
	int x, y;
	cin >> x >> y;
	if( x > 1 || y > 1 || y < -1 || x < -1){
		cout << "no";
	}else{
		cout << "yes";
	}
	return 0;
} 
