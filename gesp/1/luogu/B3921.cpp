#include<iostream>
using namespace std;
int main(){
	int a, b;
	cin >> a >> b;
	int i = a + b;
	if(i > 7){
		i -= 7; 
	}
	cout << i;
	return 0;
} 
