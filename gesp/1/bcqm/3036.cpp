#include<iostream>
using namespace std;
int main(){
	int a;
	cin >> a;
	//b十位 ,c个位。 
    int d;
	d = a % 10*10+a/10;

	cout << d;
	return 0;
}
