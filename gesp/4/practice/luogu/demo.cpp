#include<iostream>
using namespace std;

void addOne(int x){
	x = x + 1;
	cout << "函数内x = " << x << endl;
} 

int main(){
	int a = 5;
	addOne(a);
	cout << "main中的a = " << a << endl;
	return 0;
}
