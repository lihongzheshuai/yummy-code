#include<iostream>
using namespace std;
int main(){
	int a, b;
	cin >> a >> b;
	int i = b % 7;
	int j = a + i;
	if(j > 7){
		j -= 7;
	}
	cout << j;
	return 0;
} 
