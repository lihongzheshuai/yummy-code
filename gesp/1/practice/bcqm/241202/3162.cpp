#include<iostream>
using namespace std;
int main(){
	int m;
	cin >> m;
	double sum = 0.0;
	int fm = 0;
	for(int i = 1;;i++){
		fm += 1;
		sum += 1.0 / (double)fm;
		if(sum >= m){
			cout << fm;
			break;
		}
	}
	return 0;
} 
