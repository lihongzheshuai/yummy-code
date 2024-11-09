#include<iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	int min = 100;
	int point;
	for(int i = 1;i <= n;i++){
		cin >> point;
		if(point < min){
			min = point;
		}
		}
	cout << min;
	return 0;
}
