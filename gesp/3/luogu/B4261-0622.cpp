#include<iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	for(int i = 0;i<2025;i++){
		if((i&n)+(i|n)==2025){
			cout << i;
			return 0;
		}
	}
	cout << "-1";
	return 0;
}
