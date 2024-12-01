#include<iostream>
using namespace std;
int main(){
	int a;
	cin >> a;
	int ans = 0;
	int d = 1;
	int time = 0;
	while(true){
		ans += d;
		d += 1;
		time += 1;
		if(ans > a){
			break;
		}
	}
	cout << time;
	return 0;
}
