#include<iostream>
using namespace std;
int main(){
	int a;
	while(true){
		cin >> a;
		if(a >= 0 && a <= 100){
			cout << "�ɼ���" << a;
			return 0;
		}
	}
	return 0;
}
