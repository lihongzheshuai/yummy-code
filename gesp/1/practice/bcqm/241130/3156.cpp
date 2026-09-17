#include<iostream>
using namespace std;
int main(){
	int a;
	cin >> a;
	for(int i = 3;i < a;i++){
		if(i % 3 == 0){
			cout << i << endl;
		}
	}
	return 0;
}
