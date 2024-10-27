#include<iostream>
using namespace std;
int main(){
	int a, b;
	cin >> a >> b;
	int i = 1;
	for(i;i <= a;i++){
		if(i % b != 0){
			cout << i << endl;
		}
	}
	return 0;
}
