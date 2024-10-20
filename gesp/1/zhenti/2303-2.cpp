#include<iostream>
using namespace std;
int main(){
	int a;
	cin >> a;
	int c=0;
	for(int i = 1; i * i <= a;i++){
		if(a % i == 0){
			c++;
		}
	}
	cout << c;
	return 0;
}
