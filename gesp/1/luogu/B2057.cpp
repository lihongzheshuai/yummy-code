#include<iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	int max = 0;
	int point;
	for(int i = 1;i <= n;i++){
		cin >> point;
		if(point > max){
			max = point;
		}
		}
	cout << max;
	return 0;
}
